/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Parser.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Core/Parser.hpp"
#include "Pins/Abstract/APin.hpp"
#include "Error/Error.hpp"
#include "Factories/ComponentFactory.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

nts::Parser::Parser():
    part_(UNDEFINED), pins_()
{}

nts::Parser::Parser(const std::string& filePath):
    part_(UNDEFINED), filename_(filePath), pins_()
{
    std::ifstream stream;
    std::vector<std::string> args;
    std::string line;
    int i = 0;

    stream.open(filePath);
    if (!stream.is_open())
        throw FileError("Cannot open file '" + filePath + "'.");

    try {
        while (getline(stream, line)) {
            removeComments(line);
            i++;
            if (setPart(line))
                continue;

            switch (this->part_) {
                case CHIPSETS:
                    handleChipsets(line, i);
                    break;
                case LINKS:
                    handleLinks(line, i);
                    break;
                case PINS:
                    handlePins(line, i);
                    break;
                default:
                    handleHeader(line, i);
                    break;
            }
        }
    } catch (const std::exception &err) {
        stream.close();
        throw;
    }
}

// ===============================================================
//                            Getters
// ===============================================================

std::string nts::Parser::getFilename() const
{
    return this->filename_;
}

std::map<std::string, std::shared_ptr<nts::IComponent>> nts::Parser::getComponents() const
{
    return this->components_;
}

std::map<std::string, std::shared_ptr<nts::Logger>> nts::Parser::getLoggers() const
{
    return this->loggers_;
}

std::map<std::string, std::shared_ptr<nts::Clock>> nts::Parser::getClocks() const
{
    return this->clocks_;
}

std::map<std::string, std::shared_ptr<nts::Input>> nts::Parser::getInputs() const
{
    return this->inputs_;
}

std::map<std::string, std::shared_ptr<nts::Output>> nts::Parser::getOutputs() const
{
    return this->outputs_;
}

std::map<size_t, nts::IPin::PinType> nts::Parser::getPins() const
{
    return this->pins_;
}

std::map<size_t, nts::Parser::Link> nts::Parser::getSelfPins() const
{
    return this->selfPins_;
}


// ===============================================================
//                              Utils
// ===============================================================

bool nts::Parser::startsWith(const std::string& line, const std::string &start)
{
    return line.find(start) == 0;
}

bool nts::Parser::isNumber(const std::string& line)
{
    if (line.empty())
        return false;
    for (const char i : line) {
        if (i > '9' || i < '0')
            return false;
    }
    return true;
}

std::string nts::Parser::toString(const size_t n)
{
    std::stringstream s;

    s << n;
    return s.str();
}

size_t nts::Parser::toLLInt(const std::string &str)
{
    std::stringstream s(str);
    size_t n = 0;

    s >> n;
    return n;
}

bool nts::Parser::containsOnly(const std::string& line, const std::string& accepted, const size_t offset)
{
    size_t i = offset;

    while (line[i] != '\0') {
        if (accepted.find(line[i]) == std::string::npos)
            return false;
        i++;
    }
    return true;
}

void nts::Parser::removeComments(std::string &line)
{
    size_t pos(std::string::npos);

    do {
        pos = line.find('#');
        if (pos == std::string::npos)
            continue;

        line.replace(pos, line.size() - pos, "\0");
    } while (pos != std::string::npos);
}

bool nts::Parser::setPart(const std::string &line)
{
    if (startsWith(line, ".chipsets:") && containsOnly(line, " #\n", CHIPSETS)) {
        this->part_ = CHIPSETS;
        return true;
    }
    if (startsWith(line, ".links:") && containsOnly(line, " #\n", LINKS)) {
        this->part_ = LINKS;
        return true;
    }
    if (startsWith(line, ".pins:") && containsOnly(line, " #\n", PINS)) {
        this->part_ = PINS;
        return true;
    }
    return false;
}

// ===============================================================
//                             Parsing
// ===============================================================

void nts::Parser::handleHeader(const std::string &line, const int lineNb)
{
    std::stringstream stream(line);
    const std::string start;

    if (!start.empty() && !startsWith(start, "#"))
        throw ParseLineError("Non-empty line found in the headers.", this->filename_, line, lineNb);
}

void nts::Parser::handleChipsets(const std::string &line, const int lineNb)
{
    std::stringstream stream(line);

    std::string type;
    std::string name;
    std::string end;

    stream >> type;
    stream >> name;
    stream >> end;

    if (!end.empty())
        throw ParseLineError("Found token '" + end + "' at end of line.", this->filename_, line, lineNb);

    if (type.empty() && name.empty())
        return;

    if (name.empty())
        throw ParseLineError("Missing chipset name.", this->filename_, line, lineNb);

    const std::shared_ptr<IComponent> component = ComponentFactory::createComponent(type, name);
    if (component == nullptr)
        throw ComponentTypeError("The component '" + type + "' does not exists.", this->filename_, line, lineNb);

    if (this->chipsets_.find(name) != this->chipsets_.end())
        throw ParseLineError("The component '" + name + "' already exists.", this->filename_, line, lineNb);
    
    if (type == "output")
        this->outputs_[name] = std::dynamic_pointer_cast<Output>(component);
    else if (type == "logger")
        this->loggers_[name] = std::dynamic_pointer_cast<Logger>(component);
    else if (type == "input")
        this->inputs_[name] = std::dynamic_pointer_cast<Input>(component);
    else if (type == "clock")
        this->clocks_[name] = std::dynamic_pointer_cast<Clock>(component);
    else
        this->components_[name] = component;
    this->chipsets_[name] = component;
}

void nts::Parser::handleLinks(const std::string& line, const int lineNb)
{
    std::stringstream stream(line);
    std::string first;
    std::string second;
    std::string end;

    stream >> first;
    stream >> second;
    stream >> end;

    if (!end.empty())
        throw ParseLineError("Found token '" + end + "' at end of line.", this->filename_, line, lineNb);

    if (first.empty() && second.empty())
        return;

    if (second.empty())
        throw ParseLineError("Second link not found.", this->filename_, line, lineNb);

    Link link1;
    Link link2;
    try {
        link1 = Link(first);
        link2 = Link(second);
    } catch (const Error &err) {
        throw ParseLineError(err.what(), this->filename_, line, lineNb);
    }

    if (this->chipsets_.find(link1.getName()) == this->chipsets_.end())
        throw ParseLineError("Unknown component '" + link1.getName() + "'.", this->filename_, line, lineNb);
    if (this->chipsets_.find(link2.getName()) == this->chipsets_.end())
        throw ParseLineError("Unknown component '" + link2.getName() + "'.", this->filename_, line, lineNb);
    const std::shared_ptr<IComponent> component1 = this->chipsets_[link1.getName()];
    const std::shared_ptr<IComponent> component2 = this->chipsets_[link2.getName()];

    try {
        component1->setLink(link1.getPinID(), *component2, link2.getPinID());
    } catch (const Error &err) {
        throw ParseLineError(err.what(), this->filename_, line, lineNb);
    }
}

void nts::Parser::handlePins(const std::string &line, const int lineNb)
{
    std::stringstream stream(line);
    std::string data;
    std::stringstream dataStream;
    std::string end;
    std::string strPinId;
    std::string strPinType;
    size_t pinId;
    IPin::PinType pinType;

    stream >> data;
    stream >> end;

    if (!end.empty())
        throw ParseLineError("Found token '" + end + "' at end of line.", this->filename_, line, lineNb);

    if (data.empty())
        return;

    if (data.find('=') != std::string::npos)
        return this->handleSelfPins(data, line, lineNb);

    dataStream << data;
    getline(dataStream, strPinId, ':');
    getline(dataStream, strPinType, ':');

    pinId = toLLInt(strPinId);

    if (strPinType == "input")
        pinType = IPin::INPUT;
    else if (strPinType == "output")
        pinType = IPin::OUTPUT;
    else if (strPinType == "undefined")
        pinType = IPin::UNDEFINED;
    else
        throw ParseLineError("Invalid pin type '" + strPinType + "'.", this->filename_, line, lineNb);

    this->pins_[pinId] = pinType;
}

void nts::Parser::handleSelfPins(const std::string &data, const std::string &line, const int lineNb)
{
    std::stringstream dataStream(data);
    std::string strPinId;
    std::string component;
    size_t pinId = -1;

    getline(dataStream, strPinId, '=');
    getline(dataStream, component, '=');

    if (!isNumber(strPinId))
        throw ParseLineError("Invalid pin id. Expected a number, got '" + strPinId + "'.", this->filename_, line, lineNb);

    pinId = toLLInt(strPinId);
    this->selfPins_.emplace(pinId, Link(component));
}

// ===============================================================
//                              Links
// ===============================================================

nts::Parser::Link::Link():
    pinID_(0)
{}

nts::Parser::Link::Link(const std::string& data)
{
    std::stringstream stream(data);
    std::string strPinID;

    getline(stream, this->name_, ':');
    getline(stream, strPinID, ':');

    if (!isNumber(strPinID))
        throw Error("Invalid pin id '" + strPinID + "'.");
    this->pinID_ = toLLInt(strPinID);
}

nts::Parser::Link &nts::Parser::Link::operator=(const Link& rhs)
{
    if (this == &rhs)
        return *this;
    this->name_ = rhs.getName();
    this->pinID_ = rhs.getPinID();
    return *this;
}

std::string nts::Parser::Link::getName() const
{
    return this->name_;
}

size_t nts::Parser::Link::getPinID() const
{
    return this->pinID_;
}
