//custom_types.h
#ifndef CST_TYPE
#define CST_TYPE

/*---------------Booleand data definitions------------*/
#define Off (0)
#define On 	(1)
#define False (0)
#define True 	(1)

/*---------------On board LED definitions-------------*/
#define Red_LED (0x02)
#define Blue_LED (0x04) //PF2
#define Green_LED (0x08) //PF3
#define Yellow_LED (0x0A)
#define Cyan_LED (0x0C)
#define White_LED (0x0E)

/*-------------------Type Defines--------------------*/
typedef struct Xyz
{
	char z;
	char y;
	char x;
} Xyz_st;

#endif
//EOF

