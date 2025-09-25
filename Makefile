##
## EPITECH PROJECT, 2025
## OOP:NTS
## File description:
## main.c
## Author: nathan.jeannot@epitech.eu
##

NAME = nanotekspice

OK = \033[0;32m
KO = \033[0;31m
RESET = \033[0m

INCLUDES = -Isrc

CXXFLAGS = -Wall -Wextra $(INCLUDES)

SRC  = src/main.cpp

SRC += src/Pins/Abstract/APin.cpp
SRC += src/Pins/PinInput.cpp
SRC += src/Pins/PinOutput.cpp

SRC += src/Commands/CommandProcessor.cpp
SRC += src/Commands/Handlers/ExitCommandHandler.cpp
SRC += src/Commands/Handlers/DisplayCommandHandler.cpp
SRC += src/Commands/Handlers/SimulateCommandHandler.cpp
SRC += src/Commands/Handlers/LoopCommandHandler.cpp
SRC += src/Commands/Handlers/AssignCommandHandler.cpp

SRC += src/Components/Abstract/AComponent.cpp
SRC += src/Components/Circuit.cpp
SRC += src/Components/Buffer.cpp
SRC += src/Components/And.cpp
SRC += src/Components/Or.cpp
SRC += src/Components/Xor.cpp
SRC += src/Components/Not.cpp
SRC += src/Components/Clock.cpp
SRC += src/Components/Output.cpp
SRC += src/Components/Input.cpp
SRC += src/Components/False.cpp
SRC += src/Components/True.cpp
SRC += src/Components/TriState.cpp
SRC += src/Components/Nand.cpp
SRC += src/Components/Nor.cpp
SRC += src/Components/Logger.cpp
SRC += src/Components/Flipflop.cpp

SRC += src/Core/Core.cpp
SRC += src/Core/Parser.cpp

SRC += src/Factories/PinFactory.cpp
SRC += src/Factories/ComponentFactory.cpp

OBJ = $(SRC:%.cpp=%.o)

GARBAGE  = $(OBJ)
GARBAGE += vgcore.*

all: $(NAME)

$(NAME): $(OBJ)
	@ g++ -g $(CXXFLAGS) -o $(NAME) $(OBJ)						\
	&& echo -e "$(OK)[RULE] $(NAME)$(RESET)" 				\
	|| echo -e "$(KO)[RULE] $(NAME)$(RESET)"

%.o: %.cpp
	@ g++ -g $(CXXFLAGS) -c $< -o $@ 							\
	&& echo -e "$(OK)[OK] $<$(RESET)"						\
	|| echo -e "$(KO)[KO] $<$(RESET)"

clean:
	@ $(RM) -r $(GARBAGE)									\
	&& echo -e "$(OK)[RULE] CLEAN"							\
	|| echo -e "$(KO)[RULE] CLEAN"

fclean: clean
	@ $(RM) $(NAME)											\
	&& echo -e "$(OK)[RULE] FCLEAN"							\
	|| echo -e "$(KO)[RULE] FCLEAN"

re: fclean all

.PHONY: all clean fclean re
