//
//  blackjack.cpp
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	assert(argc == 4);
	assert(strcmp(argv[0], "./blackjack") == 0);
	assert(atoi(argv[1]) >= 0);
	assert(atoi(argv[2]) >= 0);
	assert( (strcmp(argv[3], "simple") == 0)
		   or (strcmp(argv[3], "counting") == 0)
		   or (strcmp(argv[3], "competitor") == 0) );

	

	return 0;
}