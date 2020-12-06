#!/usr/bin/env bash

# assume running from cpp folder
# ./scripts/make_module day05
# creates library, src_test, src files for day05 with skeleton files


MODULE=$1
MODULEUP=${MODULE^^}

read -r -d '' LIB_HEADER <<-EOT
#ifndef ${MODULEUP}_LIB_H
#define ${MODULEUP}_LIB_H

namespace ${MODULE}lib {

int lib_function();

}
#endif
EOT

read -r -d '' LIB_CPP <<-EOT
#include "${MODULE}_lib.h"

using namespace ${MODULE}lib;

int ${MODULE}lib::lib_function()
{
    return -1;
}
EOT

read -r -d '' SRC_HEADER <<-EOT
#ifndef ${MODULEUP}_H
#define ${MODULEUP}_H

#include <string>

int ${MODULE}(const std::string& filename);



#endif
EOT

read -r -d '' SRC_CPP <<-EOT
#include "${MODULE}.h"
#include "${MODULE}_lib.h"
#include <iostream>

using namespace ${MODULE}lib;

int ${MODULE}(const std::string& filename)
{
    (void)filename;
    std::cout << "Put day04 solver here!" << std::endl;
    return -1;
}
EOT

read -r -d '' TEST_HEADER <<-EOT
#ifndef ${MODULEUP}_TEST_H
#define ${MODULEUP}_TEST_H

namespace ${MODULE}test {

bool ${MODULE}_test();

}

#endif
EOT

read -r -d '' TEST_CPP <<-EOT
#include "${MODULE}_test.h"
#include "${MODULE}_lib.h"
#include "test_runner.h"

using namespace ${MODULE}lib;
using namespace ${MODULE}test;

bool ${MODULE}_test_XXX()
{
    return 0 == lib_function();
}

bool ${MODULE}_test()
{
   test_runner::Tests tests = {
        {"XXX Test", ${MODULE}_test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("${MODULE}_test", tests);
}
EOT

echo "${LIB_HEADER}" > "./library/${MODULE}_lib.h"
echo "${LIB_CPP}" > "./library/${MODULE}_lib.cpp"
echo "${SRC_HEADER}" > "./src/${MODULE}.h"
echo "${SRC_CPP}" > "./src/${MODULE}.cpp"
echo "${TEST_HEADER}" > "./src_test/${MODULE}_test.h"
echo "${TEST_CPP}" > "./src_test/${MODULE}_test.cpp"


INCLUDE_MARKER="//MAKEMODULE INCLUDE MARKER. DO NOT DELETE"
LIST_MARKER="//MAKEMODULE LIST MARKER. DO NOT DELETE"

INCLUDE_ITEM="\#include \"${MODULE}_test\.h\""
LIST_ITEM=",{\"${MODULE}_test\", ${MODULE}_test}"

# the goofiness with the $ and \\\n is to get a newline in the replacement text
sed -E -i '' -e "s~${INCLUDE_MARKER}~${INCLUDE_ITEM}"$'\\\n'"&~g" ./src_test/test_main.cpp
sed -E -i '' -e "s~${LIST_MARKER}~${LIST_ITEM}"$'\\\n'"        &~g"  ./src_test/test_main.cpp

# case 999: day02(datafile); break;
CASE_ITEM="case 999: ${MODULE}(datafile); break;"
MAIN_INCLUDE_ITEM="\#include \"${MODULE}\.h\""


sed -E -i '' -e "s~${INCLUDE_MARKER}~${MAIN_INCLUDE_ITEM}"$'\\\n'"&~g" ./src/main.cpp
sed -E -i '' -e "s~${LIST_MARKER}~${CASE_ITEM}"$'\\\n'"    &~g"  ./src/main.cpp
