#define RCC_BASE      0x40021000
#define GPIOC_BASE    0x40011000

#define RCC_APB2ENR   (*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOC_CRH     (*(volatile unsigned int *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR     (*(volatile unsigned int *)(GPIOC_BASE + 0x0C))

// একটি সাধারণ ডিলে বা অপেক্ষার ফাংশন
void delay(volatile int count) {
    while(count--);
}

int main(void) {
    // ১. পোর্ট সি-এর ক্লক অন করা
    RCC_APB2ENR |= (1 << 4);

    // ২. পিন ১৩-কে আউটপুট হিসেবে সেট করা
    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |= (0x2 << 20);

    // ৩. ইনফিনিট লুপের ভেতরে লাইট অন-অফ করা
    while(1) {
        GPIOC_ODR &= ~(1 << 13); // LED ON (LOW)
        delay(500000);           // কিছু সময় অপেক্ষা করা

        GPIOC_ODR |= (1 << 13);  // LED OFF (HIGH)
        delay(500000);           // কিছু সময় অপেক্ষা করা
    }
    return 0;
}
