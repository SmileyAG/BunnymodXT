#pragma once

/*
	This file is intended to declare symbols for accessing functions.

	Macros here must have a strict declaration format and it looks like this:

	1. The macro must begin with the SYM_ prefix.
	2. Then the name of the module from which this symbol is taken is indicated. Here is a list of the following available module names: HW_, CL_, SV_.
	3. Then the name of the function. If it's a class function then you must replace the :: with __ for format.
	4. And at the end a suffix must be added indicating the platform under which this symbol serves. Here is a list of the following available module names: _WIN, _LINUX, _MAC.
*/
