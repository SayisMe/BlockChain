#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdint>

using namespace std;

bitset<32> rightRotate(bitset<32> bitset, int d)
{
	return (bitset >> d) | (bitset << (32 - d));
}
bitset<32> leftRotate(bitset<32> bitset, int d)
{
	return (bitset << d) | (bitset >> (32 - d));
}
string addBitStrings(string first, string second)
{
	string result;  // To store the sum bits

	int carry = 0;  // Initialize carry

					// Add all bits one by one
	for (int i = 31; i >= 0; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';

		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry) + '0';

		result = (char)sum + result;

		// boolean expression for 3-bit addition
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	// if overflow, then add a leading 1
	//if (carry)
	//	result = '1' + result;

	return result;
}


bitset<32> h0(0x6a09e667), h1(0xbb67ae85), h2(0x3c6ef372), h3(0xa54ff53a),
	h4(0x510e527f), h5(0x9b05688c), h6(0x1f83d9ab), h7(0x5be0cd19);
int k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

int main()
{
	string input;
	getline(cin, input);
	//cout << bitset<8>((int)input[0]);
	bitset<8> binary[64] = {0, };
	for (int i = 0; i <= input.size(); i++)
	{
		if (i < input.size())
			binary[i] = (int)input[i];
		else if(i == input.size())
			binary[i] = 128;
	}
	binary[63] = 8 * input.size();
	if (8 * input.size() > 255)
		binary[62] = 1;
	/*
	for (int i = 0; i < 64; i++)
	{
		cout << binary[i] << ' ';
	}
	*/
	bitset<32> w[64] = { 0, };
	string str;
	for (int i = 0; i < 16; i++)
	{
		str = binary[4 * i].to_string() + binary[4 * i + 1].to_string() + binary[4 * i + 2].to_string() + binary[4 * i + 3].to_string();
		w[i] = bitset<32>(str);
	}
	
	for (int i = 16; i < 64; i++)	
	{
		bitset<32> s0, s1;
		s0 ^= rightRotate(w[i - 15], 7);
		s0 ^= rightRotate(w[i - 15], 18);
		s0 ^= (w[i - 15] >> 3);
		s1 ^= rightRotate(w[i - 2], 17);
		s1 ^= rightRotate(w[i - 2], 19);
		s1 ^= (w[i - 2] >> 10);
		w[i] = bitset<32>(addBitStrings(w[i - 16].to_string(), s0.to_string()));
		w[i] = bitset<32>(addBitStrings(w[i].to_string(), w[i - 7].to_string()));
		w[i] = bitset<32>(addBitStrings(w[i].to_string(), s1.to_string()));
		//w[i] = bitsetAdd(bitsetAdd(bitsetAdd(w[i - 16], s0), w[i - 7]), s1);
	}
	
	/*
	for (int i = 0; i < 64; i++)
	{
		cout << w[i] << ' ';
	}
	*/

	bitset<32> a = h0, b = h1, c = h2, d = h3,
		e = h4, f = h5, g = h6, h = h7;

	for (int i = 0; i < 64; i++)
	{
		bitset<32> S0, S1, ch, e_f, ne_g, temp1, temp2, a_b, a_c, b_c, maj;
		S1 ^= rightRotate(e, 6);
		S1 ^= rightRotate(e, 11);
		S1 ^= rightRotate(e, 25);
		e_f = e;
		e_f &= f;
		ne_g = ~e;
		ne_g &= g;
		ch ^= e_f;
		ch ^= ne_g;
		temp1 = bitset<32>(addBitStrings(h.to_string(), S1.to_string()));
		temp1 = bitset<32>(addBitStrings(temp1.to_string(), ch.to_string()));
		temp1 = bitset<32>(addBitStrings(temp1.to_string(), bitset<32>(k[i]).to_string()));
		temp1 = bitset<32>(addBitStrings(temp1.to_string(), w[i].to_string()));
		S0 ^= rightRotate(a, 2);
		S0 ^= rightRotate(a, 13);
		S0 ^= rightRotate(a, 22);
		a_b = a;
		a_b &= b;
		a_c = a;
		a_c &= c;
		b_c = b;
		b_c &= c;
		maj ^= a_b;
		maj ^= a_c;
		maj ^= b_c;
		temp2 = bitset<32>(addBitStrings(S0.to_string(), maj.to_string()));
		h = g;
		g = f;
		f = e;
		e = bitset<32>(addBitStrings(d.to_string(), temp1.to_string()));
		d = c;
		c = b;
		b = a;
		a = bitset<32>(addBitStrings(temp1.to_string(), temp2.to_string()));
	}
	/*
	cout << bitset<32>(h0) << endl;
	cout << bitset<32>(h1) << endl;
	cout << bitset<32>(h2) << endl;
	cout << bitset<32>(h3) << endl;
	cout << bitset<32>(h4) << endl;
	cout << bitset<32>(h5) << endl;
	cout << bitset<32>(h6) << endl;
	cout << bitset<32>(h7) << endl;
	cout << bitset<32>(a) << endl;
	cout << bitset<32>(b) << endl;
	cout << bitset<32>(c) << endl;
	cout << bitset<32>(d) << endl;
	cout << bitset<32>(e) << endl;
	cout << bitset<32>(f) << endl;
	cout << bitset<32>(g) << endl;
	cout << bitset<32>(h) << endl;
	*/
	h0 = bitset<32>(addBitStrings(h0.to_string(), a.to_string()));
	h1 = bitset<32>(addBitStrings(h1.to_string(), b.to_string()));
	h2 = bitset<32>(addBitStrings(h2.to_string(), c.to_string()));
	h3 = bitset<32>(addBitStrings(h3.to_string(), d.to_string()));
	h4 = bitset<32>(addBitStrings(h4.to_string(), e.to_string()));
	h5 = bitset<32>(addBitStrings(h5.to_string(), f.to_string()));
	h6 = bitset<32>(addBitStrings(h6.to_string(), g.to_string()));
	h7 = bitset<32>(addBitStrings(h7.to_string(), h.to_string()));

	
	cout << hex << h0.to_ulong() << h1.to_ulong() << h2.to_ulong() << h3.to_ulong()
		<< h4.to_ulong() << h5.to_ulong() << h6.to_ulong() << h7.to_ulong();
	
	return 0;
}

