#include "src/kstring.h"
#include <stdio.h>

int main(int argc, char** argv){
    kstring* hello = create_string("Hello world!"); // create string, return pointer to kstring struct
    
    append(hello, '\n'); // append symbol to end of string
    
    replace(hello, 'w', 'W'); // replace A to B
    strprint(hello); // print the string
    
    printf("%d\n", hello -> len); // print len of string
    
    if( contain_str(hello, "test") ){ // check for string contain 
        printf("contain world"); 
    }
    
    delete_string(hello); // free memory (delete string)
}
