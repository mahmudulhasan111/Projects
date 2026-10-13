//// 1. STM32F103 এর মেমরি ম্যাপ অনুযায়ী বেস অ্যাড্রেস (Base Addresses) নির্ধারণ
//#define RCC_BASE      0x40021000
//#define GPIOC_BASE    0x40011000
//
//// 2. নির্দিষ্ট রেজিস্টারগুলোর অ্যাড্রেস তৈরি করা
//#define RCC_APB2ENR   (*(volatile unsigned int *)(RCC_BASE + 0x18))
//#define GPIOC_CRH     (*(volatile unsigned int *)(GPIOC_BASE + 0x04))
//#define GPIOC_ODR     (*(volatile unsigned int *)(GPIOC_BASE + 0x0C))
//
//int main(void) {
//    // 3. Port C এর জন্য ক্লক (Clock) বা পাওয়ার চালু করা
//    RCC_APB2ENR |= (1 << 4);
//
//    // 4. PC13 পিনটিকে "আউটপুট (Output)" হিসেবে কনফিগার করা
//    GPIOC_CRH &= ~(0xF << 20);  // প্রথমে পিন ১৩-এর আগের সেটিং মুছে ফেলা
//    GPIOC_CRH |= (0x2 << 20);   // এরপর পিন ১৩-কে আউটপুট (2MHz স্পিড) হিসেবে সেট করা
//
//    // 5. LED জ্বালানো (PC13 পিনে LOW সিগন্যাল পাঠানো)
//    GPIOC_ODR &= ~(1 << 13);
//
//    // 6. মাইক্রোকন্ট্রোলারকে চলমান রাখতে একটি অসীম লুপ (Infinite loop)
//    while(1) {
//        // কোড এখানে চলতে থাকবে
//
//
//    }
//
//    return 0;
//}



// 1. বেস অ্যাড্রেস এবং Bit Banding এর অ্যাড্রেস নির্ধারণ
#define PERIPHERAL_BASE       0x40000000
#define PERIPHERAL_ALIAS_BASE 0x42000000

#define RCC_BASE      0x40021000
#define GPIOC_BASE    0x40011000

// 2. নির্দিষ্ট রেজিস্টারগুলোর অ্যাড্রেস তৈরি করা
#define RCC_APB2ENR_ADDR   (RCC_BASE + 0x18)  // Bit Banding এর জন্য পয়েন্টার ছাড়া অ্যাড্রেস
#define GPIOC_ODR_ADDR     (GPIOC_BASE + 0x0C)  // Bit Banding এর জন্য পয়েন্টার ছাড়া অ্যাড্রেস

// মাল্টিপল বিট কনফিগারেশনের জন্য অরিজিনাল পয়েন্টারটিই রাখা হলো
#define GPIOC_CRH     (*(volatile unsigned int *)(GPIOC_BASE + 0x04))

// 3. Bit Banding ম্যাক্রো (Alias অ্যাড্রেস ক্যালকুলেট করার ফর্মুলা)
#define BIT_BAND(reg_addr, bit)  (*(volatile unsigned int *)(PERIPHERAL_ALIAS_BASE + ((reg_addr - PERIPHERAL_BASE) * 32) + (bit * 4)))

// 4. নির্দিষ্ট বিটগুলোর জন্য শর্টকাট (Bit Banding Alias)
#define PORTC_CLOCK_ENABLE   BIT_BAND(RCC_APB2ENR_ADDR, 4)
#define PC13_OUTPUT          BIT_BAND(GPIOC_ODR_ADDR, 13)

int main(void) {
    // 3. Port C এর জন্য ক্লক (Clock) বা পাওয়ার চালু করা (Bit Banding)
    PORTC_CLOCK_ENABLE = 1;

    // 4. PC13 পিনটিকে "আউটপুট (Output)" হিসেবে কনফিগার করা
    // (এখানে ৪টি বিট একসাথে চেঞ্জ হচ্ছে, তাই অরিজিনাল Bitwise পদ্ধতিই ব্যবহার করতে হবে)
    GPIOC_CRH &= ~(0xF << 20);  // প্রথমে পিন ১৩-এর আগের সেটিং মুছে ফেলা
    GPIOC_CRH |= (0x2 << 20);   // এরপর পিন ১৩-কে আউটপুট (2MHz স্পিড) হিসেবে সেট করা

    // 5. LED জ্বালানো (PC13 পিনে LOW সিগন্যাল পাঠানো) (Bit Banding)
    PC13_OUTPUT = 0;

    // 6. মাইক্রোকন্ট্রোলারকে চলমান রাখতে একটি অসীম লুপ (Infinite loop)
    while(1) {
        // কোড এখানে চলতে থাকবে
    }

    return 0;
}
