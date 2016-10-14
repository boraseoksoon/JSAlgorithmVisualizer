//
//  queue_by_array.h
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef queue_by_array_h
#define queue_by_array_h

#define QUEUE_SIZE_MAX 10

#ifdef __cplusplus
extern "C"
{
#endif
    void init_queue(void);
    void clear_queue(void);
    int put(int k);
    int get(void);
    void print_queue(void);
#ifdef __cplusplus
}
#endif


#endif /* queue_by_array_h */
