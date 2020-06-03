PROVIDE(__global_pointer$ = MIN(_sdata_begin + 0x800,
  MAX(_data_begin + 0x800, . - 0x800)));
