/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// include guards
#ifndef LAB7_9_LIB_H
#define LAB7_9_LIB_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *getCredentials(const char *username);
bool authenticate(const char *username, const char *password);

// end LAB7_9_LIB_H
#endif
