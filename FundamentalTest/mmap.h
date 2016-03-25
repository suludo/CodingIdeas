1//
//  mmap.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/16/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef mmap_h
#define mmap_h

//http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=213

//Operation not supported by device

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int fd;
    void * pregion;
    if (fd= open(/*argv[1]*/"mmap.h", O_RDONLY) <0)
    {
        
        perror("failed on open");
        return -1;
    }
    cout<<"wt"<<endl;
    /*map first 4 kilobytes of fd*/
    pregion=mmap(nullptr, 4096, PROT_READ,MAP_SHARED,fd,0);
    cout<<"uhoh"<<endl;
    if (pregion==(caddr_t)-1)
    {
        perror("mmap failed---");
        return -1;
    }
    cout<<"weird"<<endl;
    close(fd); //close the physical file because we don't need it
    //access mapped memory; read the first int in the mapped file
    int val= *((int*) pregion);
    cout<<"ha?" <<val<<endl;
    return 0;
}


#endif /* mmap_h */
