Idea.

The program loops for 1 minute, during those minuts specific PHP scripts which handle API calls and MongoDB queries are called as childprocess. If the program needs return values from the childprocess then they should be called as a thread so the program is non-blocking.
