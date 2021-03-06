/* -*- c++ -*- */
/*
 * Copyright 2010,2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_GR_ANNOTATOR_ALLTOALL_IMPL_H
#define INCLUDED_GR_ANNOTATOR_ALLTOALL_IMPL_H

#include <gnuradio/blocks/annotator_alltoall.h>

namespace gr {
namespace blocks {

class annotator_alltoall_impl : public annotator_alltoall
{
private:
    uint64_t d_when;
    uint64_t d_tag_counter;
    std::vector<tag_t> d_stored_tags;

public:
    annotator_alltoall_impl(int when, size_t sizeof_stream_item);
    ~annotator_alltoall_impl();

    std::vector<tag_t> data() const { return d_stored_tags; }

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_GR_ANNOTATOR_ALLTOALL_IMPL_H */
