#include <iostream>
#include <bitset>
#include <string>

using namespace std;

bitset<32> rightRotate(bitset<32> bitset, int d)
{
	return (bitset >> d) | (bitset << (32 - d));
}

int main()
{
	int sbox[256] = {
		232, 226,  52, 242, 220, 198, 199, 237,  57, 164,   0,  63,  70, 211, 222, 137,
		62,   59,   2, 171,  77,  12,  71, 177,  83,   7, 102,  64,  75, 170, 153,  98,
		190,  36, 241, 154, 238,  39,  30, 244, 172,  50,  73,  82,  87, 145, 181, 176,
		245, 125,  31, 173, 253,  27,  17, 138, 122, 135,   5, 156, 113,  28, 118, 105,
		107, 168,   3, 225, 217, 243, 229,  19,  20,  18, 223, 109, 108, 123,  78,  96,
		208,  14, 130, 240,  97, 104, 174,  88,  58, 103, 194, 110,  81,  94,  43,  49,
		114, 139,  44, 132, 115, 142, 140, 106, 197, 169, 117,  24, 165,  29,  41, 188,
		162, 134,  15, 191, 157, 163, 231, 207,  46,  10,   8, 116,  23, 111,  74,  25,
		206,  99,   1,  11, 175, 246,  45, 200, 192,  60, 189,  90, 148, 143,  40,   6,
		69,  218, 121,  26, 100,  80, 152, 250, 179, 228, 214, 161,  34, 203, 213, 193,
		89,  204,  21, 221, 205, 233,  76, 249, 230,  51, 227, 147,  53, 149, 182, 196,
		9,    72,  47,  48, 248, 186, 167,  66, 202, 160, 183,  95,  79,  91,  32, 234,
		68,   85,  22,  67, 239, 120, 180, 150, 201, 124, 184, 178, 235,  93, 252, 216,
		127, 101,  54, 158,  55,  33, 128, 136,  61,  92,  56, 255, 187,  84, 254, 126,
		159, 185, 236, 151, 247, 141,  16, 251,  65, 209, 131, 166,   4,  35, 215, 133,
		146, 144, 224, 119,  37,  38,  86, 212, 210, 129,  13,  42, 155, 112, 219, 195
	};
	string plain, plainarr;
	getline(cin, plain);
	for (int i = 0; i < 8; i++)
	{
		if (atoi(plain.at[i]) > 60)
		{
			plain.at[i] - 51;
		}
		
	}
	return 0;
}