#pragma once
#include <iostream>
#include <chrono>
#include <thread>
void smallWait(const std::chrono::milliseconds delay);


void animation() {
	int frame{ 1 };

	while (true) {
		system("cls");
		if (frame == 4) { frame = 1; };
		switch (frame) {
			case 1:
				std::cout << "                                              /   )    \\   /        \\   " << std::endl;
				std::cout << "                                             |   |      \\ /          \\__" << std::endl;
				std::cout << "                                             |   |       O            ==" << std::endl;
				std::cout << "                                             |   |      / \\           __" << std::endl;
				std::cout << "                                              \\   )    /   \\         /  " << std::endl;
				std::cout << "                                               \\_/____/_____\\_______/   " << std::endl;
				std::cout << "     o>            ___                      _ooo08080/oo80o80\\80o080o80o" << std::endl;
				std::cout << "   {(         ____800oo__ o}              _o08808080/080808008\\080008808" << std::endl;
				std::cout << "   _/\\_______o0o808o080o0o|_____________oo080800800/80808080080\\08008008" << std::endl;
				std::cout << "   8808888800880oo088o0oo0888888880888888888808888/8880888888088\\0008888" << std::endl;
				frame += 1;
				smallWait(std::chrono::milliseconds(500));
				break;
			case 2:
				std::cout << "                                              /   )    \\   /        \\   " << std::endl;
				std::cout << "                                             |   |      \\ /          \\__" << std::endl;
				std::cout << "                                             |   |       O            ==" << std::endl;
				std::cout << "                                             |   |      / \\           __" << std::endl;
				std::cout << "                                              \\   )    /   \\         /  " << std::endl;
				std::cout << "                                               \\_/____/_____\\_______/   " << std::endl;
				std::cout << "      o>           ___                      _ooo08080/oo80o80\\80o080o80o" << std::endl;
				std::cout << "    {(        ____800oo__ o}              _o08808080/080808008\\080008808" << std::endl;
				std::cout << "   __/\\______o0o808o080o0o|_____________oo080800800/80808080080\\08008008" << std::endl;
				std::cout << "   8808888800880oo088o0oo0888888880888888888808888/8880888888088\\0008888" << std::endl;
				frame += 1;
				smallWait(std::chrono::milliseconds(500));

				break;
			case 3:
				std::cout << "                                              /   )    \\   /        \\   " << std::endl;
				std::cout << "                                             |   |      \\ /          \\__" << std::endl;
				std::cout << "                                             |   |       O            ==" << std::endl;
				std::cout << "                                             |   |      / \\           __" << std::endl;
				std::cout << "                                              \\   )    /   \\         /  " << std::endl;
				std::cout << "                                               \\_/____/_____\\_______/   " << std::endl;
				std::cout << "       o>          ___                      _ooo08080/oo80o80\\80o080o80o" << std::endl;
				std::cout << "     {(       ____800oo__ o}              _o08808080/080808008\\080008808" << std::endl;
				std::cout << "   ___/\\_____o0o808o080o0o|_____________oo080800800/80808080080\\08008008" << std::endl;
				std::cout << "   8808888800880oo088o0oo0888888880888888888808888/8880888888088\\0008888" << std::endl;
				frame += 1;
				smallWait(std::chrono::milliseconds(500));

		}
	}
	

}//std::cout << "" << std::endl;