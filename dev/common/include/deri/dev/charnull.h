/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_CHARNULL_H_
#define DERI_DEV_CHARNULL_H_

#include "char.h"

#ifdef __cplusplus

namespace deri::dev {

/**
 * Black hole character device, a.k.a. @c /dev/null
 */
class CharNull : public CharDev {
public:
  long write(const char *buf, long len) override;
};

} // namespace deri::dev

#endif // __cplusplus
#endif // DESIDERIA_CORE_INCLUDE_DERI_DEV_CHARNULL_H_
