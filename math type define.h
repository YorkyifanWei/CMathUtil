#include <stdint.h>
#define true 1
#define false 0
// #define BLACK 0x0// 黑色
// #define BLUE 0x1// 蓝色
// #define GREEN 0x2// 绿色
// #define RESEDA 0x3 // 浅绿色
// #define RED 0x4// 红色
// #define PURPLE 0x5// 紫色
// #define YELLOW 0x6// 黄色
// #define WHITE 0x7// 白色
// #define GREY 0x8// 灰色
// #define BLUISH 0x9// 淡蓝色
// #define ONDINE 0xA// 淡绿色
// #define LIGHT_ONDINE 0xB// 淡浅绿色
// #define REDDISH 0xC// 淡红色
// #define LAVENDER 0xD// 淡紫色
// #define FAINT_YELLOW 0xE// 淡黄色
// #define GLOSS_WHITE 0xF// 亮白色

/* Length */
typedef unsigned char Length;

/* Natural number */
typedef uint32_t N_set;

/* Integer number */
typedef int32_t Z_set;

/* Rational number */
typedef struct
{
    N_set Nu;// 分子
    Z_set De;// 分母
} Q_set;

/* Real number */
typedef float R_set;

/* Complex number */
typedef struct
{
    R_set Re;// 实部
    R_set Im;// 虚部
} C_set;
typedef struct
{
    R_set mod;// 模长
    R_set rad;// 辐角
} C_set_p;

/* R^(m*n) matrix */
typedef struct
{
    R_set **a;// aij refers to line i column j
    Length row;
    Length col;
} R_matrix;

/* C^(m*n) matrix */
typedef struct
{
    C_set **a;
    Length row;
    Length col;
} C_matrix;
