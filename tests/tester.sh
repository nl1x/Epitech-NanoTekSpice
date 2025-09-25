#!/usr/bin/env bash

RESET='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
GRAY='\033[1;30m'
CYAN='\033[0;36m'
L_GRAY='\033[0;37m'
YELLOW='\033[1;33m'

compile () {
  echo -ne $GRAY"--- "$ORANGE"Compiling program... $GRAY---\n"$RESET
  make -s
  echo -e $GRAY"--- "$ORANGE"Compilation done $GRAY---"$RESET
}

run_test () {
    echo -ne "$GRAY[$CYAN$4/$5$GRAY] $ORANGE$1$RESET"
    output=$(echo "$1" | bash 2>/dev/null)
    status=$?
    expected_output=$(cat $2)
    if [[ $status -ne $3 ]];
    then
        echo -e " : "$RED"KO"$RESET
        echo -e "$GRAY|--$YELLOW Expected status: $RED$3$RESET"
        echo -e "$GRAY|--$YELLOW Got status: $RED$status$RESET"
    elif [[ "$output" = "$expected_output" ]];
    then
        echo -e " : "$GREEN"OK"$RESET
    else
        echo -e " : "$RED"KO"$RESET
        echo -e "$GRAY|--$YELLOW Expected: '$RED$expected_output$YELLOW'$RESET"
        echo -e "$GRAY|--$YELLOW Got: '$RED$output$YELLOW'$RESET"
    fi
}

run_tests () {
  length=$(expr ${#tests[@]} '/' $nb_params - 1)
  for i in $(seq 0 $length); do
      run_test "cat tests/${tests[$i * $nb_params]}/commands | ./nanotekspice tests/${tests[$i * $nb_params]}/config" "tests/${tests[$i * $nb_params]}/output" ${tests[$(expr $i '*' $nb_params + 1)]} $(expr $i + 1) $(expr $length + 1) # ${tests[$(expr $i '*' $nb_params + 2)]}
  done
}

working_dir=$(pwd)
nb_params=2

declare -a tests=(

  # =======================
  #         Parser
  # =======================

  # Comment ignored
  'comment_ignored'
  0

  # Component not found
  'component_not_found'
  84

  # No chipsets
  'no_chipsets'
  84

  # No links
  'no_links'
  0

  # Invalid pin
  'invalid_pin'
  84

  # Invalid link
  'invalid_link'
  84

  # Invalid pin
  'invalid_pin_of_letter'
  84

  # Pin input already linked
  'pin_input_already_linked'
  84
  
  # pin_is_not_a_number
  'pin_is_not_a_number'
  84

  # Subject sample 2 with invalid component
  'subject_example_2'
  84
  
    # =======================
    #         Components
    # =======================
  
  # Subject sample 1 with 4071
  'subject_example_1'
  0
  
  # Subject sample 3
  'subject_example_3'
  0

  # Comment ignored
  'and_component'
  0
  
  # Nand component
  'nand_component'
  0

  # Or component
  'or_component'
  0

  # Nor component
  'nor_component'
  0
  
  # Xor component
  'xor_component'
  0

  # 4081 component
  '4081_component'
  0
  
  # 4512 component
  '4512_component'
  0
  
  # Full adder component
  'fulladder_component'
  0
  
  # 4008 component
  '4008_component'
  0
  
  # 4013 component
  '4013_component'
  0

)

compile
run_tests