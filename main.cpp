#include <iostream>
#include<cassert>
using namespace std;
char nibble_to_hex(uint8_t i)
{ assert(0x0 <= i && i <= 0xf);
char digits[]="0123456789abcdef";
return digits[i];
}
void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4);
    cout<< nibble_to_hex(byte & 0b00001111);

}


const uint8_t*
as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit >0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout<<bit_digit(byte,0);
}

    void print_in_binary(const void* data, size_t size) {
        const uint8_t* bytes = as_bytes(data);
        for (size_t i = 0; i < size; i++) {
            print_in_binary(bytes[i]);

            if ((i + 1) % 4 == 0) {
                cout << '\n';
            }
            else {
                cout << ' ';
            }
        }
    }
struct student{
    char name[17];
    uint16_t year;
    float sred_ball;
    uint8_t sex:1;
    int courseValue;
    student * starosta;
};

int main()
{
    uint16_t res,oper1,oper2;
    char oper;
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
   cin>>oper1>>oper>>oper2;
    switch (oper) {
    case '&':
        res = oper1 & oper2;
        print_in_hex(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_hex(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_hex(&res, sizeof(res));
        cout << '\n';
        print_in_binary(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_binary(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_binary(&res, sizeof(res));
        break;

    case '|':
        res=oper1|oper2;
        print_in_hex(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_hex(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_hex(&res, sizeof(res));
        cout << '\n';
        print_in_binary(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_binary(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_binary(&res, sizeof(res));
        break;

    case '^':
        res = oper1 ^ oper2;
        print_in_hex(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_hex(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_hex(&res, sizeof(res));
        cout << '\n';
        print_in_binary(&oper1, sizeof(oper1));
        cout << oper << " ";
        print_in_binary(&oper2, sizeof(oper2));
        cout << "= ";
        print_in_binary(&res, sizeof(res));
        break;

    }
    student stud[3];
    {
            stud[0];{"Ivan",19,3.9,1,1,&stud[2];

        };
    stud[1];{
            "Dania",18,1.9,1,1,&stud[2];
        };
        stud[2];{
            "Artem",18,5,1,1,nullptr;
        };
    };

cout<<'\n'<<"Address of array: "<<&stud<<'\n';
    cout<<"Size of array: "<<sizeof(stud)<<'\n';
    cout<<"Address of element: "<<"\t size of element: \n";
    for( int i=0;i<3;i++){
        cout<<i<<'\t'<<&stud[i]<<'\t'<<sizeof(stud[i])<<'\n';
    }
    cout<<"FOR FIRST ELEM OF ARREY: \n";
    cout<<"Address of field: "<<"\t size of field: "<<"\t offset: \n";
    cout<<"NAME:        \t"<<&stud[2].name;
    cout<<'\t'<<sizeof(&stud[2].name)<<"\t"<<offsetof(struct student,name)<<'\n';
    cout<<"Year:        \t"<<&stud[2].year;
    cout<<'\t'<<sizeof(&stud[2].year)<<"\t"<<offsetof(struct student,year)<<'\n';
    cout<<"sredni ball: \t"<<&stud[2].sred_ball;
    cout<<'\t'<<sizeof(&stud[2].sred_ball)<<"\t"<<offsetof(struct student,sred_ball)<<'\n';
    cout<<"course:      \t"<<&stud[2].courseValue;
    cout<<'\t'<<sizeof(&stud[2].courseValue)<<"\t"<<offsetof(struct student,courseValue)<<'\n';
    cout<<"starosta:    \t"<<&stud[2].starosta;
    cout<<'\t'<<sizeof(&stud[2].starosta)<<"\t"<<offsetof(struct student,starosta)<<'\n';
cout<<"Name:\n";
    cout<<"Binary: \n";
    print_in_binary(&stud[2].name,sizeof(stud[2].name));
    cout<<"\n Hex: \n";
    print_in_hex(&stud[2].name,sizeof(stud[2].name));
    cout<<"\n";
    cout<<"Year:\n";
    cout<<"Binary: \n";
    print_in_binary(&stud[2].year,sizeof(stud[2].year));
    cout<<"\n Hex: \n";
    print_in_hex(&stud[2].year,sizeof(stud[2].year));
    cout<<"\n";
    cout<<"sredni ball:\n";
    cout<<"Binary: \n";
    print_in_binary(&stud[2].sred_ball,sizeof(stud[2].sred_ball));
    cout<<"\n Hex: \n";
    print_in_hex(&stud[2].sred_ball,sizeof(stud[2].sred_ball));
    cout<<"\n";
    cout<<"course:\n";
    cout<<"Binary: \n";
    print_in_binary(&stud[2].courseValue,sizeof(stud[2].courseValue));
    cout<<"\n Hex: \n";
    print_in_hex(&stud[2].courseValue,sizeof(stud[2].courseValue));
    cout<<"\n";
    cout<<"starosta:\n";
    cout<<"Binary: \n";
    print_in_binary(&stud[2].starosta,sizeof(stud[2].starosta));
    cout<<"\n Hex: \n";
    print_in_hex(&stud[2].starosta,sizeof(stud[2].starosta));
    cout<<"\n";

}