#include "config.h"

config read_config();

config default_config() {
    config cfg = {
        .banner = true
    };
    return cfg;
}
