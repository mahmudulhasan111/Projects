// 1. STM32F103 এর মেমরি ম্যাপ অনুযায়ী বেস অ্যাড্রেস (Base Addresses) নির্ধারণ
#define RCC_BASE      0x40021000
#define GPIOC_BASE    0x40011000

// 2. নির্দিষ্ট রেজিস্টারগুলোর অ্যাড্রেস তৈরি করা
#define RCC_APB2ENR   (*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOC_CRH     (*(volatile unsigned int *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR     (*(volatile unsigned int *)(GPIOC_BASE + 0x0C))

int main(void) {
    // 3. Port C এর জন্য ক্লক (Clock) বা পাওয়ার চালু করা
    RCC_APB2ENR |= (1 << 4);

    // 4. PC13 পিনটিকে "আউটপুট (Output)" হিসেবে কনফিগার করা
    GPIOC_CRH &= ~(0xF << 20);  // প্রথমে পিন ১৩-এর আগের সেটিং মুছে ফেলা
    GPIOC_CRH |= (0x2 << 20);   // এরপর পিন ১৩-কে আউটপুট (2MHz স্পিড) হিসেবে সেট করা

    // 5. LED জ্বালানো (PC13 পিনে LOW সিগন্যাল পাঠানো)
    GPIOC_ODR &= ~(1 << 13);

    // 6. মাইক্রোকন্ট্রোলারকে চলমান রাখতে একটি অসীম লুপ (Infinite loop)
    while(1) {
        // কোড এখানে চলতে থাকবে


    }

    return 0;
}
