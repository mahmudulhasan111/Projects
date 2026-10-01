# print("hello world") 
# name ='masum'
# city="rajshahi"
# address="""dept of cse
# rajsahahi"""
# print(address +" "+name)


text = "Programming"

# # Indexing
# print(text[0])    # P (প্রথম অক্ষর)
# print(text[4])    # r (৫ম অক্ষর)
# print(text[-1])   # g (একদম শেষের অক্ষর)
# print(text[-2])   # n (শেষের দিক থেকে ২য় অক্ষর)
# # Slicing
# print(text[0:4])  # Prog (0 থেকে 3 পর্যন্ত নিবে, 4 নিবে না)
# print(text[3:7])  # gram
# print(text[:4])   # Prog (start না দিলে ডিফল্টভাবে 0 থেকে শুরু হয়)
# print(text[4:])   # ramming (stop না দিলে শেষ পর্যন্ত নিবে)

# # Step
# print(text[0:10:2]) # Pormi (২ ঘর লাফিয়ে লাফিয়ে নিবে)

# # স্ট্রিং উল্টে ফেলার (Reverse) ট্রিক:
# print(text[::-1])   # gnimmargorP



# word = "Hello"
# # word[0] = "J" 
# # উপরের লাইনটি রান করলে TypeError দিবে! কারণ স্ট্রিংয়ের একটি অক্ষর পাল্টানো যায় না।

# # সমাধান কী? 
# # আমরা আগের স্ট্রিংয়ের স্লাইসিংয়ের সাথে নতুন কিছু যোগ করে সম্পূর্ণ নতুন একটি স্ট্রিং বানাতে পারি।
# new_word = "J" + word[1:] 
# print(new_word) # Jello (আগের word ঠিকই আছে, আমরা নতুন ভ্যারিয়েবলে ডাটা রাখলাম)


# sentence = "  hello Python WORLD!  "

# print(sentence.lower())       # সব ছোট হাতের অক্ষর: "  hello python world!  "
# print(sentence.upper())       # সব বড় হাতের অক্ষর: "  HELLO PYTHON WORLD!  "
# print(sentence.title())       # প্রতি শব্দের প্রথম অক্ষর বড়: "  Hello Python World!  "
# print(sentence.capitalize())  # শুধু পুরো বাক্যের প্রথম অক্ষর বড় করবে।

# # স্পেস রিমুভ করা (খুবই দরকারী ইউজার ইনপুটের ক্ষেত্রে)
# print(sentence.strip())       # ডানে-বামের সব স্পেস কেটে দিবে: "hello Python WORLD!"
# print(sentence.lstrip())      # শুধু বামের (Left) স্পেস কাটবে
# print(sentence.rstrip())      # শুধু ডানের (Right) স্পেস কাটবে

# # খোঁজা এবং রিপ্লেস করা
# text = "I love Java"
# print(text.replace("Java", "Python")) # Output: I love Python
# print(text.find("love"))              # Output: 2 (যেখান থেকে শুরু হয়েছে তার ইনডেক্স দিবে)
# print(text.find("C++"))               # Output: -1 (না পেলে -1 দিবে)
# print(text.count("a"))                # Output: 2 ('a' কয়বার আছে তা গুনবে)

# # স্ট্রিং ভাঙা এবং জোড়া লাগানো (split & join)
# fruits_str = "apple,banana,mango"
# fruits_list = fruits_str.split(",")   # কমা অনুযায়ী ভেঙে লিস্ট বানাবে: ['apple', 'banana', 'mango']

# words = ['Python', 'is', 'fun']
# joined_str = " ".join(words)          # স্পেস দিয়ে লিস্টের শব্দগুলো জোড়া লাগাবে: "Python is fun"


# print(fruits_list)
# print(joined_str)




# name = "Masum"
# age = 22

# # 1. f-string (সবচেয়ে আধুনিক, সহজ এবং ফাস্ট) - স্ট্রিংয়ের আগে f বা F দিতে হয়।
# print(f"My name is {name} and I am {age} years old.")
# # Output: My name is Masum and I am 22 years old.

# # f-string এর ভেতরে সরাসরি ম্যাথ বা ফাংশনও ব্যবহার করা যায়!
# print(f"Next year, I will be {age + 1} years old.") 
# print(f"My name in uppercase is {name.upper()}")

# # 2. .format() method (আগের পদ্ধতি)
# print("My name is {} and I am {}".format(name, age))

# # 3. % operator (অনেক পুরোনো পদ্ধতি, এখন খুব একটা ব্যবহৃত হয় না)
# print("My name is %s and I am %d" % (name, age))




# # হিসাব: 10 + 3 * (2 ** 2)
# # প্রথমে 2 ** 2 = 4
# # এরপর 3 * 4 = 12
# # শেষে 10 + 12 = 22
# print(10 + 3 * 2 ** 2) # Output: 22

# # ব্র্যাকেট দিয়ে কন্ট্রোল করা:
# print((10 + 3) * 2 ** 2) # Output: 52 (আগে ব্র্যাকেটের কাজ 13, তারপর পাওয়ার 4, 13*4=52)

# # // (Floor Division) এবং % (Modulus) এর কাজ:
# print(10 / 3)   # 3.3333333333333335 (সাধারণ ভাগ)
# print(10 // 3)  # 3 (দশমিকের পরের অংশ বাদ দিয়ে পূর্ণসংখ্যা দিবে)
# print(10 % 3)   # 1 (ভাগশেষ বের করবে)






# print(abs(-50))      # 50 (Absolute/পরম মান, নেগেটিভকে পজিটিভ করে)
# print(round(3.678, 2)) # 3.68 (দশমিকের পর কয় ঘর রাখবেন তা রাউন্ড ফিগার করে)
# print(min(10, 5, 20))  # 5 (সবচেয়ে ছোট মান)
# print(max(10, 5, 20))  # 20 (সবচেয়ে বড় মান)
# print(pow(2, 3))       # 8 (২ এর পাওয়ার ৩ বা 2^3)

# # math মডিউল ব্যবহার করে (import করতে হবে)
# import math

# print(math.ceil(3.1))   # 4 (সবসময় উপরের দিকে পূর্ণসংখ্যায় নিবে)
# print(math.floor(3.9))  # 3 (সবসময় নিচের দিকে পূর্ণসংখ্যায় নিবে)
# print(math.sqrt(25))    # 5.0 (বর্গমূল বা Square Root)
# print(math.pi)          # 3.141592653589793 (পাই এর মান)








# # উদাহরণ ১: বেসিক If-Else
# age = 20
# if age >= 18:
#     # পাইথনে {} ব্র্যাকেট নাই, তাই indentation (৪টা স্পেস) দিয়ে বোঝাতে হয় যে কোডটি if এর ভেতরে।
#     print("You can vote!") 
# else:
#     print("You cannot vote.")

# # উদাহরণ ২: Elif (একাধিক শর্ত)
# marks = 75
# if marks >= 80:
#     print("A+")
# elif marks >= 70:    # else if কেই পাইথনে elif লেখা হয়
#     print("A")
# elif marks >= 60:
#     print("A-")
# else:
#     print("Below A-")

# # উদাহরণ ৩: Multiple Conditions (and, or)
# has_nid = True
# has_passport = False

# if has_nid or has_passport:
#     print("Identity verified!")
# else:
#     print("Verification failed.")

# # উদাহরণ ৪: Nested If (If এর ভেতরে If)
# num = 15
# if num > 0:
#     if num % 2 == 0:
#         print("Positive Even Number")
#     else:
#         print("Positive Odd Number")
# else:
#     print("Negative Number or Zero")









# languages = ["C", "C++", "Java"]

# # আইটেম অ্যাক্সেস
# print(languages[1])      # C++

# # আইটেম আপডেট করা
# languages[2] = "Python"  # Java পরিবর্তন হয়ে Python হয়ে যাবে

# # আইটেম যোগ করা
# languages.append("JavaScript")  # লিস্টের একদম শেষে যোগ করবে
# languages.insert(1, "Go")       # ১ নং ইনডেক্সে Go বসিয়ে বাকিগুলোকে ডানে সরিয়ে দিবে

# # আইটেম মুছে ফেলা
# languages.remove("C")           # ভ্যালু ধরে ডিলিট করবে
# popped_item = languages.pop()   # একদম শেষের আইটেম ডিলিট করবে এবং সেটা রিটার্ন করবে
# # languages.clear()             # লিস্টের সব আইটেম মুছে ফেলবে

# # অন্যান্য মেথড
# nums = [5, 2, 9, 1]
# nums.sort()       # ছোট থেকে বড় সাজাবে: [1, 2, 5, 9]
# nums.reverse()    # লিস্ট উল্টে দিবে: [9, 5, 2, 1]
# print(len(nums))  # লিস্টে কয়টি আইটেম আছে: 4






# #টুপল লিস্টের মতোই, কিন্তু এটি Immutable (একবার বানালে আর চেঞ্জ, অ্যাড বা রিমুভ করা যায় না)। এটি ফাস্ট এবং সিকিউর। লিখতে () ফার্স্ট ব্র্যাকেট ব্যবহার করা হয়। টুপলের উদাহরণ:

# rgb_colors = (255, 0, 0)
# print(rgb_colors[0]) # 255

# # rgb_colors[0] = 120  -> এটি Error দিবে! টুপল চেঞ্জ করা যায় না।

# # একটি আইটেমের টুপল বানাতে হলে শেষে কমা দিতে হয়, না হলে পাইথন একে সাধারণ ব্র্যাকেট মনে করে।
# single_tuple = (10,) 
# print(type(single_tuple)) # <class 'tuple'>






# 2.12 Range Method
# range() ফাংশন মূলত একটি সংখ্যার সিরিজ জেনারেট করে। লুপের সাথে এটি সবচেয়ে বেশি ব্যবহৃত হয়। সিনট্যাক্স: range(start, stop, step)
# উদাহরণ:
# Python
# range সরাসরি প্রিন্ট করলে অবজেক্ট দেখায়, তাই দেখার জন্য list() এ কনভার্ট করতে হয়।
# print(list(range(5)))        # [0, 1, 2, 3, 4] (স্টার্ট না দিলে 0 থেকে শুরু হয়, stop 5 এর আগে থামে)
# print(list(range(2, 8)))     # [2, 3, 4, 5, 6, 7]
# print(list(range(1, 10, 2))) # [1, 3, 5, 7, 9] (2 করে বেড়েছে)
# print(list(range(10, 0, -1)))# [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] (উল্টো দিকে)





# # =====================================================================
# # ১. রেঞ্জ (range) এর সাথে For loop
# # =====================================================================
# print("--- ১. range এর ব্যবহার ---")
# for i in range(1, 6):
#     print(f"Number is: {i}")

# print("\n" + "="*40 + "\n") # ডিভাইডার লাইন

# # =====================================================================
# # ২. লিস্টের উপর For loop
# # =====================================================================
# print("--- ২. লিস্টের উপর লুপ ---")
# students = ["Masum", "Rahim", "Karim"]
# for student in students:
#     print(f"Hello {student}")

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৩. স্ট্রিংয়ের উপর For loop
# # =====================================================================
# print("--- ৩. স্ট্রিংয়ের উপর লুপ ---")
# word = "Code"
# for letter in word:
#     print(letter)

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৪. ডিকশনারির (Dictionary) উপর For loop
# # =====================================================================
# print("--- ৪. ডিকশনারির উপর লুপ ---")
# scores = {"Masum": 85, "Rahim": 90, "Karim": 78}
# for name, score in scores.items():
#     print(f"{name} scored {score}")

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৫. লুপের সাথে শর্ত (If-Else in For loop)
# # =====================================================================
# print("--- ৫. লুপের ভেতর If-Else (জোড় সংখ্যা খোঁজা) ---")
# numbers = [1, 2, 3, 4, 5, 6]
# for num in numbers:
#     if num % 2 == 0:
#         print(f"{num} is Even (জোড়)")

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৬. ইনডেক্সসহ লুপ চালানো (Enumerate)
# # =====================================================================
# print("--- ৬. Enumerate এর ব্যবহার (ইনডেক্সসহ) ---")
# fruits = ["Mango", "Banana", "Apple"]
# for index, fruit in enumerate(fruits):
#     print(f"Index {index}: {fruit}")

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৭. রেঞ্জ (range) দিয়ে নির্দিষ্ট ব্যবধানে লুপ চালানো
# # =====================================================================
# print("--- ৭. নির্দিষ্ট ব্যবধানে (Step) লুপ ---")
# for i in range(1, 11, 2):
#     print(f"Odd number: {i}")

# print("\n" + "="*40 + "\n")

# # =====================================================================
# # ৮. লুপের মাঝপথে ব্রেক করা (Break Statement)
# # =====================================================================
# print("--- ৮. Break এর ব্যবহার ---")
# for i in range(1, 10):
#     if i == 5:
#         print("5 পাওয়া গেছে, লুপ এখানেই শেষ!")
#         break
#     print(f"Current number: {i}")








# # টাস্ক: ১ থেকে ১০ পর্যন্ত সংখ্যাগুলোর মধ্যে শুধু জোড় সংখ্যার একটি লিস্ট বানানো।

# # সাধারণ নিয়ম (Normal For Loop):
# evens = []
# for i in range(1, 11):
#     if i % 2 == 0:
#         evens.append(i)
# print(evens)

# # লিস্ট কম্প্রিহেনশন (List Comprehension - এক লাইনে):
# smart_evens = [i for i in range(1, 11) if i % 2 == 0]
# print(smart_evens) # Output: [2, 4, 6, 8, 10]

# # আরেকটি উদাহরণ: সব নামের প্রথম অক্ষর বড় করা
# names = ["masum", "rahim", "karim"]
# capitalized_names = [name.title() for name in names]
# print(capitalized_names) # ['Masum', 'Rahim', 'Karim']









# # set
# # ডুপ্লিকেট ডাটা রিমুভ করার ম্যাজিক!
# numbers_list = [1, 2, 2, 3, 3, 4, 5, 5]
# unique_numbers = set(numbers_list) 
# print(unique_numbers) # Output: {1, 2, 3, 4, 5}

# my_set = {10, 20, 30}
# my_set.add(40)      # নতুন ডাটা যোগ
# my_set.discard(20)  # ডাটা রিমুভ (remove ও ব্যবহার করা যায়, তবে discard এ ডাটা না থাকলে এরর দেয় না)

# # Mathematical Set Operations:
# A = {1, 2, 3, 4}
# B = {3, 4, 5, 6}

# print(A.union(B))         # {1, 2, 3, 4, 5, 6} (সব নিবে, কিন্তু ডুপ্লিকেট একবার) - শর্টকাট: A | B
# print(A.intersection(B))  # {3, 4} (শুধু কমন গুলো নিবে) - শর্টকাট: A & B
# print(A.difference(B))    # {1, 2} (A তে আছে কিন্তু B তে নেই) - শর্টকাট: A - B








# student = {
#     "name": "Mahamudul Hasan Masum",
#     "varsity": "Rajshahi University",
#     "department": "CSE",
#     "cgpa": 3.75
# }

# # ডাটা এক্সেস করা
# print(student["name"])       # Mahamudul Hasan Masum
# print(student.get("cgpa"))   # 3.75 (.get() ব্যবহার করা সেফ, key না থাকলে এরর দেয় না, None রিটার্ন করে)

# # ডাটা আপডেট বা নতুন ডাটা যোগ করা
# student["cgpa"] = 3.80       # ভ্যালু আপডেট
# student["session"] = "2023"  # নতুন key-value যোগ

# # ডাটা ডিলিট করা
# student.pop("session")       # session ডিলিট হয়ে যাবে
# # del student["cgpa"]        # এভাবেও ডিলিট করা যায়

# # Dictionary মেথডস এবং লুপ
# print(student.keys())        # শুধু সব key এর লিস্ট দিবে
# print(student.values())      # শুধু সব value এর লিস্ট দিবে
# print(student.items())       # key-value পেয়ার দিবে (for লুপের জন্য দরকারি)

# # ডিকশনারির উপর For Loop
# for key, value in student.items():
#     print(f"{key}: {value}")









# # টাস্ক: ১ থেকে ৫ পর্যন্ত সংখ্যার একটি ডিকশনারি বানানো যেখানে সংখ্যাটি key এবং তার বর্গ (square) হবে value।

# squares_dict = {x: x**2 for x in range(1, 6)}
# print(squares_dict)
# # Output: {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

# # শর্তযুক্ত ডিকশনারি কম্প্রিহেনশন (শুধু জোড় সংখ্যার বর্গ):
# even_squares = {x: x**2 for x in range(1, 11) if x % 2 == 0}
# print(even_squares)
# # Output: {2: 4, 4: 16, 6: 36, 8: 64, 10: 100}
