//
//  OperatorOverload.h
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#ifndef proj4_OperatorOverload_h
#define proj4_OperatorOverload_h

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}

#endif
