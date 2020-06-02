/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_CHAR_H_
#define DERI_DEV_CHAR_H_

#ifdef __cplusplus

namespace deri::dev {

class CharDev {
public:
  virtual long write(const char *buf, long len) = 0;
};

} // namespace deri::dev

#endif // __cplusplus

#endif // DERI_DEV_CHAR_H_
