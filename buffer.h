//
//  buffer.h
//  compiler
//
//  Created by skyer on 14-5-29.
//  Copyright (c) 2014年 skyer. All rights reserved.
//

#ifndef compiler_buffer_h
#define compiler_buffer_h


#include <stdio.h>

void initialize_buffer();
void code_gen();
void push_buffer(char* buf);
void pop_buffer();

#endif


