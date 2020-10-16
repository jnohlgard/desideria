/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/testing/finish.h"
namespace deri::dev {

class HostedFinisher : public deri::testing::Finisher {
public:
  [[noreturn]] void pass() override;
  [[noreturn]] void fail(unsigned int code) override;
};
} // namespace deri::dev
