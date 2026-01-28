

// #ifndef __TOKEN_PM_H__
//     #define __TOKEN_PM_H__

//     // DEBUG Flag
//     //#define DEBUG
//     ///////////////////////
//     // Offset and width of CSR fields of token FSM
//     ///////////////////////

//     // Configuration Register 0 (token FSM)
//     #define OFFSET_ENABLE           0
//     #define WIDTH_ENABLE            1
//     #define OFFSET_MAX_TOKENS       (OFFSET_ENABLE + WIDTH_ENABLE)
//     #define WIDTH_MAX_TOKENS        6
//     #define OFFSET_REFRESH_RATE_MIN (OFFSET_MAX_TOKENS + WIDTH_MAX_TOKENS)
//     #define WIDTH_REFRESH_RATE_MIN  12
//     #define OFFSET_REFRESH_RATE_MAX (OFFSET_REFRESH_RATE_MIN + WIDTH_REFRESH_RATE_MIN)
//     #define WIDTH_REFRESH_RATE_MAX  12
//     // Configuration Register 1 (token FSM)
//     #define OFFSET_ACTIVITY               0
//     #define WIDTH_ACTIVITY                1
//     #define OFFSET_RANDOM_RATE            (OFFSET_ACTIVITY + WIDTH_ACTIVITY)
//     #define WIDTH_RANDOM_RATE             5
//     #define OFFSET_LUT_WRITE              (OFFSET_RANDOM_RATE + WIDTH_RANDOM_RATE)
//     #define WIDTH_LUT_WRITE               18
//     #define OFFSET_TOKEN_COUNTER_OVERRIDE (OFFSET_LUT_WRITE + WIDTH_LUT_WRITE)
//     #define WIDTH_TOKEN_COUNTER_OVERRIDE  8
//     // Configuration Register 2 (token FSM)
//     #define OFFSET_NEIGHBORS_ID 0
//     #define WIDTH_NEIGHBORS_ID  20
//     // Configuration Register 3 (token FSM)
//     #define OFFSET_PM_NETWORK 0
//     #define WIDTH_PM_NETWORK  32
//     // Status Register 0 (token FSM)
//     #define OFFSET_TOKENS_NEXT 0
//     #define WIDTH_TOKENS_NEXT  7
//     #define OFFSET_LUT_READ    (OFFSET_TOKENS_NEXT + WIDTH_TOKENS_NEXT)
//     #define WIDTH_LUT_READ     8

//     //////////////////////////////////////////////// Macro deficnation

//     #define OFFSET_SPRINT_ENABLE   20
//     #define WIDTH_SPRINT_ENABLE     1

//     #define OFFSET_SPRINT_TOKENS   21
//     #define WIDTH_SPRINT_TOKENS     7

//     //sprint duration
//     #define OFFSET_SPRINT_DURATION 28 //token_pm2 used till 27 (21-27), 28th bit is free
//     #define WIDTH_SPRINT_DURATION 4   //there are 4 bits in total in token_pm2 that can be used for sprint duration counter


//     #define SPRINT_ENABLE_MASK (1 << OFFSET_SPRINT_ENABLE)
//     #define SPRINT_TOKENS_MASK (0x7F << OFFSET_SPRINT_TOKENS)
//     #define SPRINT_DURATION_MASK (0XF << OFFSET_SPRINT_DURATION) //since its 4 bits, 0xF is used to mask the bits


//     ////////////////////////////////////////////////

//     // CSR register offsets
//     #define TOKEN_PM_CONFIG0_REG 0x0  // 4*8
//     #define TOKEN_PM_CONFIG1_REG 0x4
//     #define TOKEN_PM_CONFIG2_REG 0x8
//     #define TOKEN_PM_CONFIG3_REG 0xc
//     #define TOKEN_PM_CONFIG4_REG 0x10
//     #define TOKEN_PM_CONFIG5_REG 0x14
//     #define TOKEN_PM_CONFIG6_REG 0x18
//     #define TOKEN_PM_CONFIG7_REG 0x1c
//     #define TOKEN_PM_CONFIG8_REG 0x20
//     #define TOKEN_PM_STATUS0_REG 0x24
//     #define TOKEN_PM_STATUS1_REG 0x28

//     // CSR config registers default values
//     #define TOKEN_PM_CONFIG0_REG_DEFAULT 0
//     #define TOKEN_PM_CONFIG1_REG_DEFAULT 0
//     #define TOKEN_PM_CONFIG2_REG_DEFAULT 0
//     #define TOKEN_PM_CONFIG3_REG_DEFAULT 0

//     #define TOKEN_PM_CONFIG4_REG_DEFAULT 0x66666666
//     #define TOKEN_PM_CONFIG5_REG_DEFAULT 0x666663E0
//     #define TOKEN_PM_CONFIG6_REG_DEFAULT 0x7CFFFFFF
//     #define TOKEN_PM_CONFIG7_REG_DEFAULT 0xFFFFF830
//     #ifdef PID_CONFIG
//         #define TOKEN_PM_CONFIG8_REG_DEFAULT 0x07FFFAA7
//     #else
//         #define TOKEN_PM_CONFIG8_REG_DEFAULT 0x2FFFFAFD
//     #endif

//     ///////////////////////
//     // Accelerator Tiles and Address Map
//     ///////////////////////
//     #define N_ACC               6
//     #define CSR_BASE_ADDR       0x60090000
//     #define CSR_TILE_OFFSET     0x200
//     #define CSR_TOKEN_PM_OFFSET 0x1d0

//     #define ACC_BASE_ADDR             0x60010000
//     #define ACC_THIRD_PARTY_BASE_ADDR 0x60400000
//     #define ACC_OFFSET                0x200
//     // Set accelerator ID (ACC_TILE_ID) according to the position of the accelerator in the
//     // SoC. Acc IDs increment from left to right and from top to bottom.
//     // Running for config
//     // cpu - IO  - nvdla
//     // FFT - Mem - Vit
//     // FFT - Vit - FFT
//     #define ACC_ID_NVDLA      0
//     #define ACC_ADDR_NVDLA    (ACC_THIRD_PARTY_BASE_ADDR + (ACC_OFFSET * ACC_ID_NVDLA))
//     #define ACC_ID_FFT0       1
//     #define ACC_ADDR_FFT0     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT0))
//     #define ACC_ID_VITERBI0   2
//     #define ACC_ADDR_VITERBI0 (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_VITERBI0))
//     #define ACC_ID_FFT1       3
//     #define ACC_ADDR_FFT1     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT1))
//     #define ACC_ID_VITERBI1   4
//     #define ACC_ADDR_VITERBI1 (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_VITERBI1))
//     #define ACC_ID_FFT2       5
//     #define ACC_ADDR_FFT2     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT2))

// // Common params
// static unsigned in_words_adj;
// static unsigned out_words_adj;
// static unsigned in_len;
// static unsigned out_len;
// static unsigned in_size;
// static unsigned out_size;
// static unsigned out_offset;
// static unsigned mem_size;
//     /* Size of the contiguous chunks for scatter/gather */
//     #define CHUNK_SHIFT 20
//     #define CHUNK_SIZE  BIT(CHUNK_SHIFT)
//     #define NCHUNK(_sz) ((_sz % CHUNK_SIZE == 0) ? (_sz / CHUNK_SIZE) : (_sz / CHUNK_SIZE) + 1)

// // Tile ID of the tiles with BlitzCoin enabled
// const unsigned acc_tile_ids[N_ACC] = {2, 3, 5, 6, 7, 8};

// ///////////////////////
// // Parameters
// ///////////////////////
// const unsigned enable_const      = 1;
// const unsigned activity_const    = 1;
// const unsigned no_activity_const = 0;

// // Value setting of the ḿax'register of the tiles with PM 63 -> NVLDA, 10 -> FFT, 36 -> Viterbi
// const unsigned max_tokens[N_ACC]      = {63, 10, 36, 10, 36, 10};
// const unsigned max_tokens_EXP0[N_ACC] = {40, 0, 40, 0, 0, 0};

// const unsigned refresh_rate_min_const[N_ACC] = {
//     97,  101, 103, 107,
//     109, 113}; // Choosing slighly different and co-prime refresh rates for the different tiles can
//                // help avoiding collisions and simplifies convergence
// const unsigned refresh_rate_max_const[N_ACC] = {97, 101, 103, 107, 109, 113};
// const unsigned total_tokens                  = 30; // Total tokens in system (Original 30)
// const unsigned total_tokens_ini              = total_tokens;

//     #define LUT_SIZE 64

// // Filled baed on each tile V,F response and our DRCo code vs freq setting
// const unsigned lut_data_const_FFT[LUT_SIZE] = {
//     255, 215, 168, 126, 98, 77, 58, 40, 24, 18, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
//     14,  14,  14,  14,  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
//     14,  14,  14,  14,  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14};

// const unsigned lut_data_const_VIT[LUT_SIZE] = {
//     255, 250, 238, 226, 214, 203, 194, 184, 175, 165, 156, 149, 142, 134, 127, 120,
//     113, 106, 101, 96,  91,  87,  82,  77,  73,  68,  63,  59,  55,  51,  47,  43,
//     39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,
//     39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39};

// const unsigned lut_data_const_NVDLA[LUT_SIZE] = {
//     255, 255, 254, 251, 247, 243, 239, 235, 231, 227, 223, 219, 215, 211, 207, 203,
//     199, 196, 192, 188, 184, 180, 176, 172, 168, 164, 160, 156, 152, 149, 145, 141,
//     137, 133, 130, 127, 125, 122, 120, 117, 115, 112, 110, 107, 104, 102, 99,  97,
//     94,  92,  89,  87,  84,  82,  79,  77,  74,  73,  71,  70,  68,  67,  65,  64};

// #endif

// const unsigned random_rate_const_0 = 0; // For tile 0
// const unsigned random_rate_const   = 17;
// /*Define neighbors for each tile*/
// /*Neighbors do not have to be physical neigbors of a given tile, this can be adjusted with CSRs */
// const unsigned int neighbors_id_const[N_ACC] = {
//     (1 << 15) + (2 << 10) + (4 << 5) + 5, (0 << 15) + (2 << 10) + (3 << 5) + 5,
//     (0 << 15) + (3 << 10) + (4 << 5) + 5, (0 << 15) + (1 << 10) + (4 << 5) + 5,
//     (0 << 15) + (1 << 10) + (3 << 5) + 5, (0 << 15) + (1 << 10) + (2 << 5) + 3};
// const unsigned int neighbors_id_const_EXP0[N_ACC] = {
//     (2 << 15) + (2 << 10) + (2 << 5) + 2,
//     0,
//     (0 << 15) + (0 << 10) + (0 << 5) + 0,
//     0,
//     0,
//     0}; // For Experiment0 only neighbor IDs are defined for tiles 0 and 2, others are unused.
// const unsigned int pm_network_const[N_ACC] = {0, 4, 1, 2, 2, 4};

// // const unsigned pm_network_const = 0;
// // Initialized by init_consts()
// // unsigned int pm_network_const[N_ACC];
// unsigned token_counter_override[N_ACC];

// #define TOKEN_NEXT_MASK 0x7f

// ///////////////////////
// // Tests
// ///////////////////////

// // Set of tests of the bare-metal app.
// // Uncomment the tests that you want to execute
// //#define TEST_0 0
// //// basic test for coin exchange between 2 tiles
// #define TEST_1 1
// //// Test covering coin exchange for 6 tiles with Blitzcoin running parallel workloads on FFT,
// ///Viterbi and NVDLA
// ///////////////////////
// // Functions
// ///////////////////////

// void init_consts()
// {
//     int n;
//     unsigned remaining_tokens = total_tokens_ini;

//     for (n = 0; n < N_ACC; n++) {
//         // 1 for all accs part of token PM

//         if (remaining_tokens > (1 << 6 - 1)) {
//             token_counter_override[n] = (1 << 7) + 1 << 6 - 1;
//             remaining_tokens          = remaining_tokens - 1 << 6;
//         }
//         else {
//             token_counter_override[n] = (1 << 7) + remaining_tokens;
//             remaining_tokens          = 0;
//         }
//     }
// }

// void reset_blitzcoin(struct esp_device espdevs[])
// {
//     int i;

//     printf("Reset CSRs\n");

//     for (i = 0; i < N_ACC; i++) {
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG0_REG, TOKEN_PM_CONFIG0_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG1_REG, TOKEN_PM_CONFIG1_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG2_REG, TOKEN_PM_CONFIG2_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG3_REG, TOKEN_PM_CONFIG3_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG4_REG, TOKEN_PM_CONFIG4_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG5_REG, TOKEN_PM_CONFIG5_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG6_REG, TOKEN_PM_CONFIG6_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG7_REG, TOKEN_PM_CONFIG7_REG_DEFAULT);
//         iowrite32(&espdevs[i], TOKEN_PM_CONFIG8_REG, TOKEN_PM_CONFIG8_REG_DEFAULT);
//     }
// }

// void write_config0(struct esp_device *espdev, unsigned enable, unsigned max_tokens,
//                    unsigned refresh_rate_min, unsigned refresh_rate_max)
// {
//     unsigned val;

//     val = (refresh_rate_max << OFFSET_REFRESH_RATE_MAX) |
//         (refresh_rate_min << OFFSET_REFRESH_RATE_MIN) | (max_tokens << OFFSET_MAX_TOKENS) |
//         (enable << OFFSET_ENABLE);

//     iowrite32(espdev, TOKEN_PM_CONFIG0_REG, val);
// }

// void write_config1(struct esp_device *espdev, unsigned activity, unsigned random_rate,
//                    unsigned lut_write, unsigned token_counter_override)
// {
//     unsigned val;

//     val = (token_counter_override << OFFSET_TOKEN_COUNTER_OVERRIDE) |
//         (lut_write << OFFSET_LUT_WRITE) | (random_rate << OFFSET_RANDOM_RATE) |
//         (activity << OFFSET_ACTIVITY);

//     iowrite32(espdev, TOKEN_PM_CONFIG1_REG, val);
// }

// void write_config2(struct esp_device *espdev, unsigned neighbors_id)
// {
//     iowrite32(espdev, TOKEN_PM_CONFIG2_REG, neighbors_id);
// }

// void write_config3(struct esp_device *espdev, unsigned pm_network)
// {
//     iowrite32(espdev, TOKEN_PM_CONFIG3_REG, pm_network);
// }

// /////////////////////////////////// 
// void write_sprint(struct esp_device *espdev, unsigned sprint_enable, unsigned sprint_tokens, unsigned sprint_duration)
// {
//     unsigned val, neighbors_existing;

//     // Read existing neighbors configuration
//     neighbors_existing = ioread32(espdev, TOKEN_PM_CONFIG2_REG) & 0xFFFFF; 

//     val = neighbors_existing | 
//           ((sprint_enable & 0x1) << OFFSET_SPRINT_ENABLE) |
//           ((sprint_tokens & 0x7F) << OFFSET_SPRINT_TOKENS) |
//           ((sprint_duration & 0xF) << OFFSET_SPRINT_DURATION); ///updated to reset sprint_duration to ensure a clean update

//     iowrite32(espdev, TOKEN_PM_CONFIG2_REG, val);
// }

// // -----------------------------
// // Blitzcoin NoC (router) CSRs -- pranavi
// // -----------------------------
// // NOTE: These are written to the *router* CSR space (noc_domain_socket CSRs),
// // not the token_pm CSR space.

// // addr[6:2] = 20 => byte offset = 20 << 2 = 0x50
// // #define SPRINT_CFG_REG  (16 << 2) //20 * 4 

// // // [0] sprint_enable
// // // [7:1] sprint_tokens (7 bits)
// // // [23:8] sprint_duration (16 bits)
// // static inline unsigned encode_sprint_cfg(unsigned sprint_duration,
// //                                         unsigned sprint_tokens,
// //                                         unsigned sprint_enable)
// // {
// //     return ((sprint_enable  & 0x1)    << 0) |
// //            ((sprint_tokens  & 0x7F)   << 1) |
// //            ((sprint_duration & 0xFFFF) << 8);
// // }

// // static inline void write_sprint_cfg(struct esp_device *router_dev,
// //                                     unsigned sprint_duration,
// //                                     unsigned sprint_tokens,
// //                                     unsigned sprint_enable)
// // {
// //     iowrite32(router_dev, SPRINT_CFG_REG,
// //               encode_sprint_cfg(sprint_duration, sprint_tokens, sprint_enable));
// // }


// // // addr[6:2] = 21 => byte offset = 21 << 2 = 0x54
// // #define THERMAL_CFG_REG (31 << 2)

// // // THERMAL_CFG layout (23 bits total):
// // // [9:0]   cycle_threshold (10 bits)
// // // [16:10] percent_threshold (7 bits)
// // // [22:17] sprint_offset (6 bits)
// // static inline unsigned encode_thermal_cfg(unsigned sprint_offset,
// //                                          unsigned percent_threshold,
// //                                          unsigned cycle_threshold)
// // {
// //     return ((cycle_threshold     & 0x3FF) << 0)  |
// //            ((percent_threshold   & 0x7F)  << 10) |
// //            ((sprint_offset       & 0x3F)  << 17);
// // }

// // static inline void write_thermal_cfg(struct esp_device *router_dev,
// //                                     unsigned sprint_offset,
// //                                     unsigned percent_threshold,
// //                                     unsigned cycle_threshold)
// // {
// //     iowrite32(router_dev, THERMAL_CFG_REG,
// //               encode_thermal_cfg(sprint_offset, percent_threshold, cycle_threshold));
// // }



// ///////////////////////////////////

// void wait_for_token_next(struct esp_device *espdev, unsigned tokens_next_expected)
// {
//     while (tokens_next_expected != (ioread32(espdev, TOKEN_PM_STATUS0_REG) & TOKEN_NEXT_MASK))
//         ;
// }

// void write_lut(struct esp_device espdevs[], const unsigned lut_data[LUT_SIZE], unsigned random_rate,
//                unsigned activity, unsigned myindex)
// {
//     int i, j;
//     unsigned reg_val = 0, lut_val = 0;

//     // printf("Write LUT\n");

//     for (j = 0; j < LUT_SIZE; j++) {
//         lut_val = (1 << 17) | (0 << 16) | (lut_data[j] << 8) | j;
//         write_config1(&espdevs[myindex], activity, random_rate, lut_val, 0);
//     }
// }

// void write_lut_all(struct esp_device espdevs[], const unsigned lut_data[LUT_SIZE],
//                    unsigned random_rate, unsigned activity)
// {
//     int i, j;
//     unsigned reg_val = 0, lut_val = 0;

//     printf("Write LUT\n");

//     for (i = 0; i < N_ACC; i++) {
//         for (j = 0; j < LUT_SIZE; j++) {
//             lut_val = (1 << 17) | (0 << 16) | (lut_data[j] << 8) | j;
//             write_config1(&espdevs[i], activity, random_rate, lut_val, 0);
//         }
//     }
// }

// static inline uint64_t get_counter()
// {
//     uint64_t counter;
//     asm volatile("li t0, 0;"
//                  "csrr t0, mcycle;"
//                  "mv %0, t0"
//                  : "=r"(counter)
//                  :
//                  : "t0");
//     return counter;
// }



#ifndef __TOKEN_PM_H__
    #define __TOKEN_PM_H__

    // DEBUG Flag
    //#define DEBUG
    ///////////////////////
    // Offset and width of CSR fields of token FSM
    ///////////////////////

    // Configuration Register 0 (token FSM)
    #define OFFSET_ENABLE           0
    #define WIDTH_ENABLE            1
    #define OFFSET_MAX_TOKENS       (OFFSET_ENABLE + WIDTH_ENABLE)
    #define WIDTH_MAX_TOKENS        6
    #define OFFSET_REFRESH_RATE_MIN (OFFSET_MAX_TOKENS + WIDTH_MAX_TOKENS)
    #define WIDTH_REFRESH_RATE_MIN  12
    #define OFFSET_REFRESH_RATE_MAX (OFFSET_REFRESH_RATE_MIN + WIDTH_REFRESH_RATE_MIN)
    #define WIDTH_REFRESH_RATE_MAX  12
    // Configuration Register 1 (token FSM)
    #define OFFSET_ACTIVITY               0
    #define WIDTH_ACTIVITY                1
    #define OFFSET_RANDOM_RATE            (OFFSET_ACTIVITY + WIDTH_ACTIVITY)
    #define WIDTH_RANDOM_RATE             5
    #define OFFSET_LUT_WRITE              (OFFSET_RANDOM_RATE + WIDTH_RANDOM_RATE)
    #define WIDTH_LUT_WRITE               18
    #define OFFSET_TOKEN_COUNTER_OVERRIDE (OFFSET_LUT_WRITE + WIDTH_LUT_WRITE)
    #define WIDTH_TOKEN_COUNTER_OVERRIDE  8
    // Configuration Register 2 (token FSM)
    #define OFFSET_NEIGHBORS_ID 0
    #define WIDTH_NEIGHBORS_ID  20
    // Configuration Register 3 (token FSM)
    #define OFFSET_PM_NETWORK 0
    #define WIDTH_PM_NETWORK  32
    // Status Register 0 (token FSM)
    #define OFFSET_TOKENS_NEXT 0
    #define WIDTH_TOKENS_NEXT  7
    #define OFFSET_LUT_READ    (OFFSET_TOKENS_NEXT + WIDTH_TOKENS_NEXT)
    #define WIDTH_LUT_READ     8

    //////////////////////////////////////////////// Macro deficnation

    //#define OFFSET_SPRINT_ENABLE   20
    //#define WIDTH_SPRINT_ENABLE     1

    //#define OFFSET_SPRINT_TOKENS   21
    //#define WIDTH_SPRINT_TOKENS     7

    ////sprint duration
    //#define OFFSET_SPRINT_DURATION 28 //token_pm2 used till 27 (21-27), 28th bit is free
    //#define WIDTH_SPRINT_DURATION 4   //there are 4 bits in total in token_pm2 that can be used for sprint duration counter


    //#define SPRINT_ENABLE_MASK (1 << OFFSET_SPRINT_ENABLE)
    //#define SPRINT_TOKENS_MASK (0x7F << OFFSET_SPRINT_TOKENS)
    //#define SPRINT_DURATION_MASK (0XF << OFFSET_SPRINT_DURATION) //since its 4 bits, 0xF is used to mask the bits


    ////////////////////////////////////////////////

    // CSR register offsets
    #define TOKEN_PM_CONFIG0_REG 0x0  // 4*8
    #define TOKEN_PM_CONFIG1_REG 0x4
    #define TOKEN_PM_CONFIG2_REG 0x8
    #define TOKEN_PM_CONFIG3_REG 0xc
    #define TOKEN_PM_CONFIG4_REG 0x10
    #define TOKEN_PM_CONFIG5_REG 0x14
    #define TOKEN_PM_CONFIG6_REG 0x18
    #define TOKEN_PM_CONFIG7_REG 0x1c
    #define TOKEN_PM_CONFIG8_REG 0x20
    #define TOKEN_PM_STATUS0_REG 0x24
    #define TOKEN_PM_STATUS1_REG 0x28

    // CSR config registers default values
    #define TOKEN_PM_CONFIG0_REG_DEFAULT 0
    #define TOKEN_PM_CONFIG1_REG_DEFAULT 0
    #define TOKEN_PM_CONFIG2_REG_DEFAULT 0
    #define TOKEN_PM_CONFIG3_REG_DEFAULT 0

    #define TOKEN_PM_CONFIG4_REG_DEFAULT 0x66666666
    #define TOKEN_PM_CONFIG5_REG_DEFAULT 0x666663E0
    #define TOKEN_PM_CONFIG6_REG_DEFAULT 0x7CFFFFFF
    #define TOKEN_PM_CONFIG7_REG_DEFAULT 0xFFFFF830
    #ifdef PID_CONFIG
        #define TOKEN_PM_CONFIG8_REG_DEFAULT 0x07FFFAA7
    #else
        #define TOKEN_PM_CONFIG8_REG_DEFAULT 0x2FFFFAFD
    #endif

    ///////////////////////
    // Accelerator Tiles and Address Map
    ///////////////////////
    #define N_ACC               6
    #define CSR_BASE_ADDR       0x60090000
    #define CSR_TILE_OFFSET     0x200
    #define CSR_TOKEN_PM_OFFSET 0x1d0

    #define ACC_BASE_ADDR             0x60010000
    #define ACC_THIRD_PARTY_BASE_ADDR 0x60400000
    #define ACC_OFFSET                0x200
    // Set accelerator ID (ACC_TILE_ID) according to the position of the accelerator in the
    // SoC. Acc IDs increment from left to right and from top to bottom.
    // Running for config
    // cpu - IO  - nvdla
    // FFT - Mem - Vit
    // FFT - Vit - FFT
    #define ACC_ID_NVDLA      0
    #define ACC_ADDR_NVDLA    (ACC_THIRD_PARTY_BASE_ADDR + (ACC_OFFSET * ACC_ID_NVDLA))
    #define ACC_ID_FFT0       1
    #define ACC_ADDR_FFT0     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT0))
    #define ACC_ID_VITERBI0   2
    #define ACC_ADDR_VITERBI0 (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_VITERBI0))
    #define ACC_ID_FFT1       3
    #define ACC_ADDR_FFT1     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT1))
    #define ACC_ID_VITERBI1   4
    #define ACC_ADDR_VITERBI1 (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_VITERBI1))
    #define ACC_ID_FFT2       5
    #define ACC_ADDR_FFT2     (ACC_BASE_ADDR + (ACC_OFFSET * ACC_ID_FFT2))

// Common params
static unsigned in_words_adj;
static unsigned out_words_adj;
static unsigned in_len;
static unsigned out_len;
static unsigned in_size;
static unsigned out_size;
static unsigned out_offset;
static unsigned mem_size;
    /* Size of the contiguous chunks for scatter/gather */
    #define CHUNK_SHIFT 20
    #define CHUNK_SIZE  BIT(CHUNK_SHIFT)
    #define NCHUNK(_sz) ((_sz % CHUNK_SIZE == 0) ? (_sz / CHUNK_SIZE) : (_sz / CHUNK_SIZE) + 1)

// Tile ID of the tiles with BlitzCoin enabled
const unsigned acc_tile_ids[N_ACC] = {2, 3, 5, 6, 7, 8};

///////////////////////
// Parameters
///////////////////////
const unsigned enable_const      = 1;
const unsigned activity_const    = 1;
const unsigned no_activity_const = 0;

// Value setting of the ḿax'register of the tiles with PM 63 -> NVLDA, 10 -> FFT, 36 -> Viterbi
const unsigned max_tokens[N_ACC]      = {63, 10, 36, 10, 36, 10};
const unsigned max_tokens_EXP0[N_ACC] = {40, 0, 40, 0, 0, 0};

const unsigned refresh_rate_min_const[N_ACC] = {
    97,  101, 103, 107,
    109, 113}; // Choosing slighly different and co-prime refresh rates for the different tiles can
               // help avoiding collisions and simplifies convergence
const unsigned refresh_rate_max_const[N_ACC] = {97, 101, 103, 107, 109, 113};
const unsigned total_tokens                  = 30; // Total tokens in system (Original 30)
const unsigned total_tokens_ini              = total_tokens;

    #define LUT_SIZE 64

// Filled baed on each tile V,F response and our DRCo code vs freq setting
const unsigned lut_data_const_FFT[LUT_SIZE] = {
    255, 215, 168, 126, 98, 77, 58, 40, 24, 18, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14,  14,  14,  14,  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14,  14,  14,  14,  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14};

const unsigned lut_data_const_VIT[LUT_SIZE] = {
    255, 250, 238, 226, 214, 203, 194, 184, 175, 165, 156, 149, 142, 134, 127, 120,
    113, 106, 101, 96,  91,  87,  82,  77,  73,  68,  63,  59,  55,  51,  47,  43,
    39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,
    39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,  39};

const unsigned lut_data_const_NVDLA[LUT_SIZE] = {
    255, 255, 254, 251, 247, 243, 239, 235, 231, 227, 223, 219, 215, 211, 207, 203,
    199, 196, 192, 188, 184, 180, 176, 172, 168, 164, 160, 156, 152, 149, 145, 141,
    137, 133, 130, 127, 125, 122, 120, 117, 115, 112, 110, 107, 104, 102, 99,  97,
    94,  92,  89,  87,  84,  82,  79,  77,  74,  73,  71,  70,  68,  67,  65,  64};

#endif

const unsigned random_rate_const_0 = 0; // For tile 0
const unsigned random_rate_const   = 17;
/*Define neighbors for each tile*/
/*Neighbors do not have to be physical neigbors of a given tile, this can be adjusted with CSRs */
const unsigned int neighbors_id_const[N_ACC] = {
    (1 << 15) + (2 << 10) + (4 << 5) + 5, (0 << 15) + (2 << 10) + (3 << 5) + 5,
    (0 << 15) + (3 << 10) + (4 << 5) + 5, (0 << 15) + (1 << 10) + (4 << 5) + 5,
    (0 << 15) + (1 << 10) + (3 << 5) + 5, (0 << 15) + (1 << 10) + (2 << 5) + 3};
const unsigned int neighbors_id_const_EXP0[N_ACC] = {
    (2 << 15) + (2 << 10) + (2 << 5) + 2,
    0,
    (0 << 15) + (0 << 10) + (0 << 5) + 0,
    0,
    0,
    0}; // For Experiment0 only neighbor IDs are defined for tiles 0 and 2, others are unused.
const unsigned int pm_network_const[N_ACC] = {0, 4, 1, 2, 2, 4};

// const unsigned pm_network_const = 0;
// Initialized by init_consts()
// unsigned int pm_network_const[N_ACC];
unsigned token_counter_override[N_ACC];

#define TOKEN_NEXT_MASK 0x7f

///////////////////////
// Tests
///////////////////////

// Set of tests of the bare-metal app.
// Uncomment the tests that you want to execute
//#define TEST_0 0
//// basic test for coin exchange between 2 tiles
#define TEST_1 1
//// Test covering coin exchange for 6 tiles with Blitzcoin running parallel workloads on FFT,
///Viterbi and NVDLA
///////////////////////
// Functions
///////////////////////

void init_consts()
{
    int n;
    unsigned remaining_tokens = total_tokens_ini;

    for (n = 0; n < N_ACC; n++) {
        // 1 for all accs part of token PM

        if (remaining_tokens > (1 << 6 - 1)) {
            token_counter_override[n] = (1 << 7) + 1 << 6 - 1;
            remaining_tokens          = remaining_tokens - 1 << 6;
        }
        else {
            token_counter_override[n] = (1 << 7) + remaining_tokens;
            remaining_tokens          = 0;
        }
    }
}

void reset_blitzcoin(struct esp_device espdevs[])
{
    int i;

    printf("Reset CSRs\n");

    for (i = 0; i < N_ACC; i++) {
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG0_REG, TOKEN_PM_CONFIG0_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG1_REG, TOKEN_PM_CONFIG1_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG2_REG, TOKEN_PM_CONFIG2_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG3_REG, TOKEN_PM_CONFIG3_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG4_REG, TOKEN_PM_CONFIG4_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG5_REG, TOKEN_PM_CONFIG5_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG6_REG, TOKEN_PM_CONFIG6_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG7_REG, TOKEN_PM_CONFIG7_REG_DEFAULT);
        iowrite32(&espdevs[i], TOKEN_PM_CONFIG8_REG, TOKEN_PM_CONFIG8_REG_DEFAULT);
    }
}

void write_config0(struct esp_device *espdev, unsigned enable, unsigned max_tokens,
                   unsigned refresh_rate_min, unsigned refresh_rate_max)
{
    unsigned val;

    val = (refresh_rate_max << OFFSET_REFRESH_RATE_MAX) |
        (refresh_rate_min << OFFSET_REFRESH_RATE_MIN) | (max_tokens << OFFSET_MAX_TOKENS) |
        (enable << OFFSET_ENABLE);

    iowrite32(espdev, TOKEN_PM_CONFIG0_REG, val);
}

void write_config1(struct esp_device *espdev, unsigned activity, unsigned random_rate,
                   unsigned lut_write, unsigned token_counter_override)
{
    unsigned val;

    val = (token_counter_override << OFFSET_TOKEN_COUNTER_OVERRIDE) |
        (lut_write << OFFSET_LUT_WRITE) | (random_rate << OFFSET_RANDOM_RATE) |
        (activity << OFFSET_ACTIVITY);

    iowrite32(espdev, TOKEN_PM_CONFIG1_REG, val);
}

void write_config2(struct esp_device *espdev, unsigned neighbors_id)
{
    iowrite32(espdev, TOKEN_PM_CONFIG2_REG, neighbors_id);
}

void write_config3(struct esp_device *espdev, unsigned pm_network)
{
    iowrite32(espdev, TOKEN_PM_CONFIG3_REG, pm_network);
}

// -----------------------------
// CSR Read Functions for Verification
// -----------------------------

// Read token PM config registers
static inline unsigned read_config0(struct esp_device *espdev)
{
    return ioread32(espdev, TOKEN_PM_CONFIG0_REG);
}

static inline unsigned read_config1(struct esp_device *espdev)
{
    return ioread32(espdev, TOKEN_PM_CONFIG1_REG);
}

static inline unsigned read_config2(struct esp_device *espdev)
{
    return ioread32(espdev, TOKEN_PM_CONFIG2_REG);
}

static inline unsigned read_config3(struct esp_device *espdev)
{
    return ioread32(espdev, TOKEN_PM_CONFIG3_REG);
}

// Read token PM status register
static inline unsigned read_status0(struct esp_device *espdev)
{
    return ioread32(espdev, TOKEN_PM_STATUS0_REG);
}

// Note: read_sprint_cfg and read_thermal_cfg are defined later after SPRINT_CFG_REG/THERMAL_CFG_REG

// Verification helper: read back and print CSR values
void verify_config0(struct esp_device *espdev, const char *tile_name, 
                    unsigned expected_enable, unsigned expected_max_tokens,
                    unsigned expected_refresh_rate_min, unsigned expected_refresh_rate_max)
{
    unsigned read_val = read_config0(espdev);
    unsigned read_enable = (read_val >> OFFSET_ENABLE) & ((1 << WIDTH_ENABLE) - 1);
    unsigned read_max_tokens = (read_val >> OFFSET_MAX_TOKENS) & ((1 << WIDTH_MAX_TOKENS) - 1);
    unsigned read_refresh_rate_min = (read_val >> OFFSET_REFRESH_RATE_MIN) & ((1 << WIDTH_REFRESH_RATE_MIN) - 1);
    unsigned read_refresh_rate_max = (read_val >> OFFSET_REFRESH_RATE_MAX) & ((1 << WIDTH_REFRESH_RATE_MAX) - 1);
    
    printf("  %s CONFIG0: 0x%08x\n", tile_name, read_val);
    printf("    enable: %u (expected %u) %s\n", read_enable, expected_enable, 
           (read_enable == expected_enable) ? "OK" : "FAIL");
    printf("    max_tokens: %u (expected %u) %s\n", read_max_tokens, expected_max_tokens,
           (read_max_tokens == expected_max_tokens) ? "OK" : "FAIL");
    printf("    refresh_rate_min: %u (expected %u) %s\n", read_refresh_rate_min, expected_refresh_rate_min,
           (read_refresh_rate_min == expected_refresh_rate_min) ? "OK" : "FAIL");
    printf("    refresh_rate_max: %u (expected %u) %s\n", read_refresh_rate_max, expected_refresh_rate_max,
           (read_refresh_rate_max == expected_refresh_rate_max) ? "OK" : "FAIL");
}

void verify_config2(struct esp_device *espdev, const char *tile_name, unsigned expected_neighbors_id)
{
    unsigned read_val = read_config2(espdev);
    unsigned read_neighbors = read_val & ((1 << WIDTH_NEIGHBORS_ID) - 1);
    
    printf("  %s CONFIG2: 0x%08x\n", tile_name, read_val);
    printf("    neighbors_id: 0x%05x (expected 0x%05x) %s\n", read_neighbors, expected_neighbors_id,
           (read_neighbors == expected_neighbors_id) ? "OK" : "FAIL");
}

// Note: verify_sprint_cfg, verify_thermal_cfg, dump_token_pm_csrs, dump_router_csrs
// are defined later after read_sprint_cfg and read_thermal_cfg

// -----------------------------
// Example Usage for CSR Verification:
// -----------------------------
// 
// After writing any CSR, you can verify it was written correctly:
//
// 1. For Token PM CSRs (espdevs):
//    verify_config0(&espdevs[i], "Tile0", enable, max_tokens, refresh_min, refresh_max);
//    verify_config2(&espdevs[i], "Tile0", neighbors_id);
//    dump_token_pm_csrs(&espdevs[i], "Tile0");  // Print all values
//
// 2. For Router/NoC CSRs (routerdevs):
//    write_sprint_cfg(&routerdevs[i], duration, tokens, enable);
//    verify_sprint_cfg(&routerdevs[i], "Tile0", enable, tokens, duration);
//    
//    write_thermal_cfg(&routerdevs[i], sprint_offset, percent_thresh, cycle_thresh);
//    verify_thermal_cfg(&routerdevs[i], "Tile0", cycle_thresh, percent_thresh, sprint_offset);
//    dump_router_csrs(&routerdevs[i], "Tile0");  // Print all values
//
// 3. Simple read-back (no verification):
//    unsigned val = read_config0(&espdevs[i]);
//    printf("CONFIG0 = 0x%08x\n", val);

/////////////////////////////////// 
// //void write_sprint(struct esp_device *espdev, unsigned sprint_enable, unsigned sprint_tokens, unsigned sprint_duration)
// //{
//     unsigned val, neighbors_existing;

//     // Read existing neighbors configuration
//     neighbors_existing = ioread32(espdev, TOKEN_PM_CONFIG2_REG) & 0xFFFFF; 

//     val = neighbors_existing | 
//           ((sprint_enable & 0x1) << OFFSET_SPRINT_ENABLE) |
//           ((sprint_tokens & 0x7F) << OFFSET_SPRINT_TOKENS) |
//           ((sprint_duration & 0xF) << OFFSET_SPRINT_DURATION); ///updated to reset sprint_duration to ensure a clean update

//     iowrite32(espdev, TOKEN_PM_CONFIG2_REG, val);
// }

// -----------------------------
// Blitzcoin NoC (router) CSRs -- pranavi
// -----------------------------
// NOTE: These are written to the *router* CSR space (noc_domain_socket CSRs),
// not the token_pm CSR space.

// CSR addresses must be in the 0x180-0x1FF range (bits [8:7] = "11")
// addr[6:2] selects the CSR register (0-31)
// SPRINT_CFG_ADDR = 16, so byte offset = 0x180 + (16 << 2) = 0x1C0
#define SPRINT_CFG_REG  (0x180 + (16 << 2))  // = 0x1C0 

// [0] sprint_enable
// [7:1] sprint_tokens (7 bits)
// [23:8] sprint_duration (16 bits)
static inline unsigned encode_sprint_cfg(unsigned sprint_duration,
                                        unsigned sprint_tokens,
                                        unsigned sprint_enable)
{
    return ((sprint_enable  & 0x1)    << 0) |
           ((sprint_tokens  & 0x7F)   << 1) |
           ((sprint_duration & 0xFFFF) << 8);
}

static inline void write_sprint_cfg(struct esp_device *router_dev,
                                    unsigned sprint_duration,
                                    unsigned sprint_tokens,
                                    unsigned sprint_enable)
{
    iowrite32(router_dev, SPRINT_CFG_REG,
              encode_sprint_cfg(sprint_duration, sprint_tokens, sprint_enable));
}


// THERMAL_CFG_ADDR = 31, so byte offset = 0x180 + (31 << 2) = 0x1FC
#define THERMAL_CFG_REG (0x180 + (31 << 2))  // = 0x1FC

// THERMAL_CFG layout (23 bits total):
// [9:0]   cycle_threshold (10 bits)
// [16:10] percent_threshold (7 bits)
// [22:17] sprint_offset (6 bits)
static inline unsigned encode_thermal_cfg(unsigned sprint_offset,
                                         unsigned percent_threshold,
                                         unsigned cycle_threshold)
{
    return ((cycle_threshold     & 0x3FF) << 0)  |
           ((percent_threshold   & 0x7F)  << 10) |
           ((sprint_offset       & 0x3F)  << 17);
}

static inline void write_thermal_cfg(struct esp_device *router_dev,
                                    unsigned sprint_offset,
                                    unsigned percent_threshold,
                                    unsigned cycle_threshold)
{
    iowrite32(router_dev, THERMAL_CFG_REG,
              encode_thermal_cfg(sprint_offset, percent_threshold, cycle_threshold));
}

// Read router/NoC CSRs (sprint and thermal config)
static inline unsigned read_sprint_cfg(struct esp_device *router_dev)
{
    return ioread32(router_dev, SPRINT_CFG_REG);
}

static inline unsigned read_thermal_cfg(struct esp_device *router_dev)
{
    return ioread32(router_dev, THERMAL_CFG_REG);
}

// Verification functions for sprint and thermal CSRs
void verify_sprint_cfg(struct esp_device *router_dev, const char *tile_name,
                       unsigned expected_sprint_enable, unsigned expected_sprint_tokens, 
                       unsigned expected_sprint_duration)
{
    unsigned read_val = read_sprint_cfg(router_dev);
    unsigned read_enable = (read_val >> 0) & 0x1;
    unsigned read_tokens = (read_val >> 1) & 0x7F;
    unsigned read_duration = (read_val >> 8) & 0xFFFF;
    
    printf("  %s SPRINT_CFG: 0x%08x\n", tile_name, read_val);
    printf("    sprint_enable: %u (expected %u) %s\n", read_enable, expected_sprint_enable,
           (read_enable == expected_sprint_enable) ? "OK" : "FAIL");
    printf("    sprint_tokens: %u (expected %u) %s\n", read_tokens, expected_sprint_tokens,
           (read_tokens == expected_sprint_tokens) ? "OK" : "FAIL");
    printf("    sprint_duration: %u (expected %u) %s\n", read_duration, expected_sprint_duration,
           (read_duration == expected_sprint_duration) ? "OK" : "FAIL");
}

void verify_thermal_cfg(struct esp_device *router_dev, const char *tile_name,
                        unsigned expected_cycle_threshold, unsigned expected_percent_threshold,
                        unsigned expected_sprint_offset)
{
    unsigned read_val = read_thermal_cfg(router_dev);
    unsigned read_cycle_threshold = (read_val >> 0) & 0x3FF;
    unsigned read_percent_threshold = (read_val >> 10) & 0x7F;
    unsigned read_sprint_offset = (read_val >> 17) & 0x3F;
    
    printf("  %s THERMAL_CFG: 0x%08x\n", tile_name, read_val);
    printf("    cycle_threshold: %u (expected %u) %s\n", read_cycle_threshold, expected_cycle_threshold,
           (read_cycle_threshold == expected_cycle_threshold) ? "OK" : "FAIL");
    printf("    percent_threshold: %u (expected %u) %s\n", read_percent_threshold, expected_percent_threshold,
           (read_percent_threshold == expected_percent_threshold) ? "OK" : "FAIL");
    printf("    sprint_offset: %u (expected %u) %s\n", read_sprint_offset, expected_sprint_offset,
           (read_sprint_offset == expected_sprint_offset) ? "OK" : "FAIL");
}

// Simple debug function: print all CSR values for a tile (no comparison)
void dump_token_pm_csrs(struct esp_device *espdev, const char *tile_name)
{
    printf("\n=== %s Token PM CSRs ===\n", tile_name);
    printf("  CONFIG0: 0x%08x\n", read_config0(espdev));
    printf("  CONFIG1: 0x%08x\n", read_config1(espdev));
    printf("  CONFIG2: 0x%08x\n", read_config2(espdev));
    printf("  CONFIG3: 0x%08x\n", read_config3(espdev));
    printf("  STATUS0: 0x%08x\n", read_status0(espdev));
}

void dump_router_csrs(struct esp_device *router_dev, const char *tile_name)
{
    printf("\n=== %s Router/NoC CSRs ===\n", tile_name);
    printf("  SPRINT_CFG: 0x%08x\n", read_sprint_cfg(router_dev));
    printf("  THERMAL_CFG: 0x%08x\n", read_thermal_cfg(router_dev));
}

///////////////////////////////////

void wait_for_token_next(struct esp_device *espdev, unsigned tokens_next_expected)
{
    while (tokens_next_expected != (ioread32(espdev, TOKEN_PM_STATUS0_REG) & TOKEN_NEXT_MASK))
        ;
}

void write_lut(struct esp_device espdevs[], const unsigned lut_data[LUT_SIZE], unsigned random_rate,
               unsigned activity, unsigned myindex)
{
    int i, j;
    unsigned reg_val = 0, lut_val = 0;

    // printf("Write LUT\n");

    for (j = 0; j < LUT_SIZE; j++) {
        lut_val = (1 << 17) | (0 << 16) | (lut_data[j] << 8) | j;
        write_config1(&espdevs[myindex], activity, random_rate, lut_val, 0);
    }
}

void write_lut_all(struct esp_device espdevs[], const unsigned lut_data[LUT_SIZE],
                   unsigned random_rate, unsigned activity)
{
    int i, j;
    unsigned reg_val = 0, lut_val = 0;

    printf("Write LUT\n");

    for (i = 0; i < N_ACC; i++) {
        for (j = 0; j < LUT_SIZE; j++) {
            lut_val = (1 << 17) | (0 << 16) | (lut_data[j] << 8) | j;
            write_config1(&espdevs[i], activity, random_rate, lut_val, 0);
        }
    }
}

static inline uint64_t get_counter()
{
    uint64_t counter;
    asm volatile("li t0, 0;"
                 "csrr t0, mcycle;"
                 "mv %0, t0"
                 : "=r"(counter)
                 :
                 : "t0");
    return counter;
}

