#pragma once

#include "node.h"

#include <memory>
#include <iostream>
#include <sstream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
