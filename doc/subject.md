# ft_containers
# C++ containers, easy mode
C++ 컨테이너, 이지 모드

Summary:
요약:

The standard C++ containers have all a specific usage.
표준 C++ 컨테이너 모두 특정 용도가 있습니다.

To make sure you understand them, let’s re-implement them!
여러분이 그것들을 확실히 이해할 수 있도록, 그것들을 다시 구현해 봅시다!

Version: 4


# Chapter I
# Objectives
# 객관적

In this project, you will implement a few container types of the C++ standard template library.
이 프로젝트에서는 C++ 표준 템플릿 라이브러리의 몇 가지 컨테이너 유형을 구현합니다.

You have to take the structure of each standard container as reference.
각 표준 컨테이너의 구조를 기준으로 삼아야 합니다.

If a part of the Orthodox Canonical form is missing in it, do not implement it.
정규 표준 양식 중 일부가 누락된 경우 이를 구현하지 마십시오.

As a reminder, you have to comply with the C++98 standard, so any later feature of the containers MUST NOT be implemented, but every C++98 feature (even deprecated ones) is expected
주의사항으로 C++98 표준을 준수해야 하므로 컨테이너의 이후 기능은 구현되지 않아야 하지만 모든 C++98 기능(비사용 기능)이 필요합니다.

# Chapter II
# General rules


**Compiling**
• Compile your code with c++ and the flags -Wall -Wextra -Werror
c++와 -Wall -Wextra -Werror 플래그를 사용하여 코드를 컴파일합니다.

• Your code should still compile if you add the flag -std=c++98
• -flag=c++98 플래그를 추가하는 경우에도 코드는 컴파일되어야 합니다 

**Formatting and naming conventions**
**형식 및 명명 규칙**

• For each container, turn in the appropriately named class files.
• 각 컨테이너에 대해 적절한 이름의 클래스 파일을 제출합니다.

• Goodbye Norminette! No coding style is enforced. You can follow your favorite one.
• 안녕, 노미네트! 코딩 스타일은 적용되지 않습니다. 마음에 드는 걸 따르면 됩니다.

But keep in mind that a code your peer-evaluators can’t understand is a code they can’t grade.
그러나 동료 평가자가 이해할 수 없는 코드는 등급을 매길 수 없는 코드라는 점을 명심하십시오.

Do your best to write a clean and readable code.
깨끗하고 읽기 쉬운 코드를 작성하기 위해 최선을 다하세요.

**Allowed/Forbidden**
**허용/금지**

You are not coding in C anymore. Time to C++! Therefore:
당신은 더 이상 C로 코딩하지 않습니다. C++ 타임! 따라서:

• You are allowed to use everything from the standard library.
• 표준 라이브러리의 모든 것을 사용할 수 있습니다.

Thus, instead of sticking to what you already know, it would be smart to use as much as possible the C++-ish versions of the C functions you are used to.
따라서 이미 알고 있는 것을 고수하기보다는 익숙한 C 함수의 C++-ish 버전을 최대한 많이 사용하는 것이 현명할 것이다.

• However, you can’t use any other external library.
• 그러나 다른 외부 라이브러리는 사용할 수 없습니다.

It means C++11 (and derived forms) and Boost libraries are forbidden.
이는 C++11(및 파생 형식)과 Boost 라이브러리가 금지됨을 의미합니다.

The following functions are forbidden too: *printf(), *alloc() and free().
*printf(), *alloc() 및 free() 기능도 사용할 수 없습니다.

If you use them, your grade will be 0 and that’s it.
이걸 쓰면 점수가 0이 되고 그게 끝이에요.

**A few design requirements**
**몇 가지 설계 요구 사항**

• Memory leakage occurs in C++ too. When you allocate memory, you must avoid **memory leaks.**
• C++에서도 메모리 누수가 발생합니다. 메모리를 할당할 때는 ** 메모리 누출을 방지해야 합니다.**

• Any function implementation put in a header file (except for function templates) means 0 to the exercise.
• 헤더 파일에 입력된 기능 구현(기능 템플릿 제외)은 연습에 대해 0을 의미한다.

• You should be able to use each of your headers independently from others.
• 각 헤더를 다른 헤더와 독립적으로 사용할 수 있어야 합니다.

Thus, they must include all the dependencies they need.
따라서 필요한 모든 종속성을 포함해야 합니다.

However, you must avoid the problem of double inclusion by adding **include guards**. Otherwise, your grade will be 0.
그러나 **include guards**를 추가하여 이중 포함 문제를 피해야 합니다. 그렇지 않으면 성적이 0이 됩니다.


**Read me**

• You can add some additional files if you need to (i.e., to split your code) and organize your work as you wish as long as you turn in the mandatory files.
• 필요한 경우(즉, 코드를 분할하기 위해) 파일을 추가하고 필수 파일을 제출하는 한 원하는 대로 작업을 구성할 수 있습니다.

• By Odin, by Thor! Use your brain!!!
• 오딘, 토르! 머리를 써!!!


빨강
Since your task here is to recode the STL containers, you of course cannot use them in order to implement yours.
여기서의 작업은 STL 컨테이너를 다시 인코딩하는 것이므로, STL 컨테이너를 사용하여 구현할 수는 없습니다.



# Chapter III
# Mandatory part
# 필수 부분

Implement the following containers and turn in the necessary <container>.hpp files:
다음 컨테이너를 구현하고 필요한 <container>.hpp 파일을 제출합니다.

• vector
You don’t have to do the vector<bool> specialization.
vector<bool>을 특수화할 필요는 없습니다.

• map

• stack (구현 안할  예정)
It will use your vector class as default underlying container.
벡터 클래스가 기반 컨테이너로 사용됩니다.

But it must still be compatible with other containers, the STL ones included.
그러나 STL이 포함된 다른 컨테이너와 호환되어야 합니다.


파랭이
You can pass this assignment without the stack (80/100).
스택(80/100) 없이도 통과할 수 있습니다.

But if you want to do the bonus part, you have to implement the 3 mandatory containers: vector, map and stack.
하지만 보너스 부분을 하려면 벡터, 맵, 스택의 세 가지 필수 컨테이너를 구현해야 합니다.

You also have to implement:
또한 다음을 구현해야 합니다.

• iterators_traits - o
• reverse_iterator - o
• enable_if - o
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
네, C++11이지만 C++98 방식으로 구현할 수 있습니다.

This is asked so you can discover SFINAE.
SFINAE를 찾을 수 있도록 질문합니다.

• is_integral - o
• equal - o
• lexicographical_compare - o
• std::pair
• std::make_pair


## III.1 Requirements
## III.1 요구 사항

• The namespace must be ft.
• 네임스페이스는 ft여야 합니다.

• Each inner data structure used in your containers must be logical and justified (this means using a simple array for map is not ok).
• 컨테이너에 사용되는 각 내부 데이터 구조는 논리적이고 정당해야 합니다. 즉, map에 단순 배열을 사용하는 것은 허용되지 않습니다.

• You cannot implement more public functions than the ones offered in the standard containers.
• 표준 컨테이너에서 제공되는 기능보다 더 많은 공용 기능을 구현할 수 없습니다.

Everything else must be private or protected. Each public function or variable must be justified.
다른 모든 것은 private이거나 protected여야 합니다. 각 public 함수 또는 변수는 정당해야 합니다.

• All the member functions, non-member functions and overloads of the standard containers are expected.
• 표준 컨테이너의 모든 멤버 기능, 비멤버 기능 및 오버로드가 필요합니다.

• You must follow the original naming. Take care of details.
• 원래 이름을 따라야 합니다. 세세한 부분까지 처리하세요.

• If the container has an iterator system, you must implement it.
• 컨테이너에 반복자가 있는 경우 이를 구현해야 합니다.

• You must use std::allocator.
• std::allocator를 사용해야 합니다.

• For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
• 비구성원 오버로드의 경우 키워드 friend가 허용됩니다. friend의 각 사용은 정당해야 하며 평가 중에 점검될 것이다.

• Of course, for the implementation of map::value_compare, the keyword friend is allowed.
• 물론 map::value_compare의 구현에서는 키워드 friend가 허용됩니다.

파랭이
You can use https://www.cplusplus.com/ and https://cppreference.com/ as references.


## III.2 Testing
• You must also provide tests, at least a main.cpp, for your defense.
• 또한 방어를 위해 최소한 main.cpp 테스트를 제공해야 합니다.

You have to go further than the main given as example!
예시로 주어진 메인보다 더 멀리 가야 해요!

• You must produce two binaries that run the same tests: one with your containers only, and the other one with the STL containers.
• 동일한 테스트를 실행하는 두 개의 이진 파일을 생성해야 합니다.
 하나는 사용자 컨테이너만 있는 것이고, 다른 하나는 STL 컨테이너가 있는 것입니다.

• Compare outputs and performance / timing (your containers can be up to 20 times slower).
• 출력과 성능/타이밍을 비교합니다(containers는 최대 20배 느릴 수 있습니다).

• Test your containers with: ft::<container>
• ft::<container>로 컨테이너 테스트

파랭이
A main.cpp file is available to download on the intranet project page.
main.cpp 파일은 인트라넷 프로젝트 페이지에서 다운로드할 수 있습니다.



# Chapter V
## Submission and peer-evaluation
## 제출 및 동료 평가

Turn in your assignment in your Git repository as usual.
평소처럼 Git 저장소에 과제를 제출하세요.

Only the work inside your repository will be evaluated during the defense.
저장소 내부의 작업만 방어 중에 평가됩니다.

Don’t hesitate to double check the names of your files to ensure they are correct.
파일 이름이 올바른지 확인하려면 파일 이름을 두 번 확인하십시오.