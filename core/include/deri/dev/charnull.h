/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_CHARNULL_H_
#define DERI_DEV_CHARNULL_H_

#include "deri/dev/char.h"

#ifdef __cplusplus

namespace deri::dev {

class CharNull : public CharDev {
public:
  long write(const char *buf, long len) override;
};

} // namespace deri::dev

#endif // __cplusplus
#endif // DESIDERIA_CORE_INCLUDE_DERI_DEV_CHARNULL_H_
