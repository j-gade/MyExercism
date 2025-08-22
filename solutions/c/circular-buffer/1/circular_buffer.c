#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "circular_buffer.h"

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    assert(capacity);

    circular_buffer_t* new_buffer =
        (circular_buffer_t*)malloc(sizeof(circular_buffer_t));
        assert(new_buffer != NULL);

        new_buffer->buffer = (buffer_value_t*)calloc(capacity, sizeof(buffer_value_t));
        assert(new_buffer->buffer != NULL);

        new_buffer->capacity = capacity;
        new_buffer->head = 0;
        new_buffer->tail = 0;

        return new_buffer;
}

void clear_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL);

    buffer->head = buffer->tail = 0;
}

void delete_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL);

    free(buffer->buffer);
    buffer->buffer = NULL;
    free(buffer);
    buffer = NULL;
    return;
}

static bool is_empty(circular_buffer_t* buffer)
{
    return buffer->head == buffer->tail;
}

static size_t next_head(circular_buffer_t* buffer)
{
    size_t next = buffer->head + 1;
    return next <= buffer->capacity ? next : 0;
}

static size_t next_tail(circular_buffer_t* buffer)
{
    size_t next = buffer->tail + 1;
    return next <= buffer->capacity ? next : 0;
}

static bool is_full(circular_buffer_t* buffer)
{
    return next_head(buffer) == buffer->tail;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    assert(buffer != NULL);
   
    if (is_full(buffer)) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->buffer[buffer->head] = value;
    buffer->head = next_head(buffer);
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    if (is_full(buffer)) {
        buffer_value_t oldest;
        read(buffer, &oldest);
    }
    return write(buffer, value);
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    assert(buffer != NULL && value != NULL);

    if (is_empty(buffer)) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *value = buffer->buffer[buffer->tail];
    buffer->tail = next_tail(buffer);
    return EXIT_SUCCESS;
}
