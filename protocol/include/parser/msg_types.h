#ifndef MSG_TYPES_H
#define MSG_TYPES_H

#define EMPTY_MSG               0
#define SML_MSG_SIZE            16
#define MED_MSG_SIZE            32
#define LRG_MSG_SIZE            64

#define INIT_BYTES              1
#define META_FLAG_BYTES         1
#define TOPIC_BYTES             1
#define SUBTOPIC_BYTES          1
#define DATA_FLAG_BYTES         1
#define RESERVED_BYTES          3
#define NON_DATA_BYTES          INIT_BYTES+META_FLAG_BYTES+TOPIC_BYTES+ \
                                SUBTOPIC_BYTES+DATA_FLAG_BYTES+RESERVED_BYTES
                                
#define LRG_MSG_DATA_BYTES      LRG_MSG_SIZE-NON_DATA_BYTES
#define MED_MSG_DATA_BYTES      MED_MSG_SIZE-NON_DATA_BYTES
#define SML_MSG_DATA_BYTES      SML_MSG_SIZE-NON_DATA_BYTES

typedef unsigned char byte_t;

typedef struct message_t
{
    byte_t init[INIT_BYTES];
    byte_t meta_flags[META_FLAG_BYTES];
    byte_t topic_id[TOPIC_BYTES];
    byte_t subtopic_id[SUBTOPIC_BYTES];
    byte_t data_flags[DATA_FLAG_BYTES];
    byte_t data[MED_MSG_DATA_BYTES];
    byte_t reserved[RESERVED_BYTES];
} message_t;

#endif