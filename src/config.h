#ifndef STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef CONFIG_H
    #define CONFIG_H    

    struct config {
        bool banner;
    };
    typedef struct config config;

    /* Reads the config file .crshrc and returns the configuration in Config */
    config read_config(void);

    /* Returns the default CrazyShell configuration */
    config default_config(void);
#endif
