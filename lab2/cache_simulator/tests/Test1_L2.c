#include "../src/2/L2Cache.h"
#include <stdint.h>

int main() {
    uint32_t clock;
    uint32_t val;

    resetTime();
    initCaches();

    /* Loads a block and then causes a miss */
    /* After that it reads from the original block again */
    clock = getTime();
    printf("Time: %d\n", clock);

    read(1, (uint8_t *)&val);

    clock = getTime();
    printf("Time: %d\n", clock);

    val = 17;
    write(1, (uint8_t *)&val);

    clock = getTime();
    printf("Time: %d\n", clock);

    val = 0;
    read(32768, (uint8_t *)&val);

    clock = getTime();
    printf("Time: %d\n", clock);

    read(1, (uint8_t *)&val);

    clock = getTime();
    printf("Value: %d\n", val);
    printf("Time: %d\n", clock);

    return 0;
}
