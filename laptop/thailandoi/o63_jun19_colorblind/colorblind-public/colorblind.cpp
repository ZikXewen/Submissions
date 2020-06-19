#include "grader.cpp"
std::string investivate_colors(int N) {
	if(N == 1) return "RB";
	std::string str = "R";
	int ori = use_device(0, 1);
	if(use_device(0, 2) == ori){
		if(use_device(1, 2) == ori) str += "RR";
		else str += "BR";
	} else {
		if(use_device(1, 2) == ori) str += "BB";
		else str += "RB";
	}
	for(int i = 3; i < (N << 1); ++i)
		str += (use_device(0, i) == ori? 'R' : 'B');
	return str;
}