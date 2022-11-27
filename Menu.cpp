#include "Menu.h"
#include <Windows.h>

fstream fsst, fsdrt, fsfilm, fscr, fsscd, fstk, fsslr;
StaffManager stMng;
DirectorManager drtMng;
FilmManager filmMng;
CinemaRoomManager cnmMng;
ScheduleManager scdMng(filmMng, cnmMng);
TicketManager tkMng(scdMng, stMng);
HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu::qlrcp() {
	SetConsoleTextAttribute(cl, 10);
	SetConsoleCursorPosition(cl, { 104, 4 });
	cout << "   ___                               _       _      ____                  ";
	SetConsoleCursorPosition(cl, { 104, 5 });
	cout << "  / _ \\   _   _    __ _   _ __      | |     (_)    |  _ \\    __ _   _ __  ";
	SetConsoleCursorPosition(cl, { 104, 6 });
	cout << " | | | | | | | |  / _` | | '_ \\     | |     | |    | |_) |  / _` | | '_ \\ ";
	SetConsoleCursorPosition(cl, { 104, 7 });
	cout << " | |_| | | |_| | | (_| | | | | |    | |___  | |    |  _ <  | (_| | | |_) |";
	SetConsoleCursorPosition(cl, { 104, 8 });
	cout << "  \\__\\_\\  \\__,_|  \\__,_| |_| |_|    |_____| |_|    |_| \\_\\  \\__,_| | .__/ ";
	SetConsoleCursorPosition(cl, { 104, 9 });
	cout << "                                                                   |_|    ";
	SetConsoleCursorPosition(cl, { 106, 10 });
	cout << "   ____   _       _                     ____    _       _             ";
	SetConsoleCursorPosition(cl, { 106, 11 });
	cout << "  / ___| | |__   (_)   ___   _   _     |  _ \\  | |__   (_)  _ __ ___  ";
	SetConsoleCursorPosition(cl, { 106, 12 });
	cout << " | |     | '_ \\  | |  / _ \\ | | | |    | |_) | | '_ \\  | | | '_ ` _ \\ ";
	SetConsoleCursorPosition(cl, { 106, 13 });
	cout << " | |___  | | | | | | |  __/ | |_| |    |  __/  | | | | | | | | | | | |";
	SetConsoleCursorPosition(cl, { 106, 14 });
	cout << "  \\____| |_| |_| |_|  \\___|  \\__,_|    |_|     |_| |_| |_| |_| |_| |_|";
}
void Menu::welcome() {
	SetConsoleTextAttribute(cl, 9);
	SetConsoleCursorPosition(cl, { 112, 30 });
	cout << " _       __           __                                    ";
	SetConsoleCursorPosition(cl, { 112, 31 });
	cout << "| |     / /  ___     / /  _____   ____     ____ ___     ___ ";
	SetConsoleCursorPosition(cl, { 112, 32 });
	cout << "| | /| / /  / _ \\   / /  / ___/  / __ \\   / __ `__ \\   / _ \\";
	SetConsoleCursorPosition(cl, { 112, 33 });
	cout << "| |/ |/ /  /  __/  / /  / /__   / /_/ /  / / / / / /  /  __/";
	SetConsoleCursorPosition(cl, { 112, 34 });
	cout << "|__/|__/   \\___/  /_/   \\___/   \\____/  /_/ /_/ /_/   \\___/ ";
}
void Menu::pic1() {
	cout << "\n\t                                                                 :!J               ";
	cout << "\n\t                                                              ~#@@@@:              ";
	cout << "\n\t                                                      .:?GG...?@@@@@^.             ";
	cout << "\n\t                                                     ?@@@@@:..!@@@@@^..            ";
	cout << "\n\t                                            .~JB&#...J@@@@@:..~@@@@@!...           ";
	cout << "\n\t                                       .: ..5@@@@&:..7@@@@@^..^@@@@@~              ";
	cout << "\n\t                                   ^Y#&@&...J@@@@@:..~@@@@@!..:B5!:                ";
	cout << "\n\t                             :77...P@@@@&:..7@@@@@^..^@@@&B:                       ";
	cout << "\n\t                          ?#@@@&...J@@@@@:..!@@@@@~...?~.                          ";
	cout << "\n\t                  .^?G5.::P@@@@&...7@@@@@^..~@@&GJ.                                ";
	cout << "\n\t            .:...5@@@@&B###@@@@@:..!@@@@@^...:.                                    ";
	cout << "\n\t         ~YGBG^..G@&#B#&&BP@@@@@^..~&#P7:                                          ";
	cout << "\n\t        JBBBBBP^:P#GGGBP7.7@@@@&:                                                  ";
	cout << "\n\t       :BBBBBBBGGBGGG#&7..^GY~.                                                    ";
	cout << "\n\t       GBBBBBBBBBBB#&@@@GY7.                                                       ";
	cout << "\n\t      YBBBBBBBBBBBG#@@@@@#&Y   :~~~~~    ^~~~~~    ^~~~~^    ~~~~~^   .~~~~~:		";
	cout << "\n\t    .YBBBBBBBBBBBBBBB@@@@@#...~@@@@@B...7@@@@@5...J@@@@@J...P@@@@@7...B@@@@@^		";
	cout << "\n\tYBGYGBBBBBBBBBBBBBBG&@@@@&:..:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@?.		";
	cout << "\n\t&&#BBBBBBBBBBBBBBBG#@@@@@~...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..		";
	cout << "\n\t7&&#GGBBBBBBBBBBBB#@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@&:..^@@@@@B...		";
	cout << "\n\t.^B&&BGBBBBBBBBB5J@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:		";
	cout << "\n\t...?#&#BBBPPYJ!:  ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:		";
	cout << "\n\t....:JB#5:        ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........		";
	cout << "\n\t........          ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........		";
	cout << "\n\t.....             ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB?...........		";
	cout << "\n\t..                ..........:??????????????J?JJJJ?J?JJJJJJJJJJJJJ~...........		";
	cout << "\n\t                  .........!77777777777777777^...777777?7777777777?^.........		";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJYYYYJJJJJJJJJ^.........		";
	cout << "\n\t                  .........J55555555555555555!..:5PPPPPPPPPPPPPPPPP^.........		";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?J??????????????JJ^.........		";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........		";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77JYPGG5????????J~..:?JJJJJJJJJJJJ?????^.........		";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................		";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.												";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.													";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.														";
	cout << "\n\t......:5B57																		";
	cout << "\n\t........																			";
	cout << "\n\t...																				";
}
void Menu::pic2() {
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                 .^75B:			";
	cout << "\n\t                                                          .:~ ..7@@@@@^			";
	cout << "\n\t                                                       7#&@@&...J@@@@@:.			";
	cout << "\n\t                                              :!YG&Y...#@@@@B...5@@@@&:..			";
	cout << "\n\t                                       .~?:..:@@@@@Y...#@@@@G...P@@@@&...			";
	cout << "\n\t                                .   ^&@@@@~..^@@@@@?...&@@@@P...B@@@#Y				";
	cout << "\n\t                           :?P#&&:..?@@@@@^..^@@@@@7..:@@@@@Y.. ~^.				";
	cout << "\n\t                   .^75?...G@@@@&...?@@@@@:..!@@@@@!..:BPJ!:						";
	cout << "\n\t           .^~^:..#@@@@#GBP&@@@@#...Y@@@@@:..7@@&B5.								";
	cout << "\n\t         !PBBBP:.:@@&#B&&&#&@@@@B...P@@@@#.. .:									";
	cout << "\n\t        !BBBBBB?:7#BGGGBP7:&@@@@G...?Y!:.											";
	cout << "\n\t       ~BBBBBBBGGBGGGB&Y...&&BPJ.													";
	cout << "\n\t      :BBBBBBBBBBBB#&@@@P?~.														";
	cout << "\n\t     ^GBBBBBBBBBBBG&@@@@@B#J   :~~~~~    ^~~~~~    ^~~~~^    ~~~~~^   .~~~~~:		";
	cout << "\n\t~7!:JBBBBBBBBBBBBBBGB@@@@@B:..~@@@@@B...7@@@@@5...J@@@@@J...P@@@@@7...B@@@@@^		";
	cout << "\n\t&&BBBBBBBBBBBBBBBBBG#@@@@&:..:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@7.		";
	cout << "\n\t&&#GBBBBBBBBBBBBBBG&@@@@@~...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..		";
	cout << "\n\t7#&#GBBBBBBBBBBBBPG@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@#...^@@@@@B...		";
	cout << "\n\t.~B&&BGGBBBBBBG5~^@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:		";
	cout << "\n\t..:J&&&#5??!~:.   ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:		";
	cout << "\n\t....^JJ^          ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........		";
	cout << "\n\t.....             ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........		";
	cout << "\n\t.                 ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB7...........		";
	cout << "\n\t                  ..........:??????????????J?JJJJ?J?JJJJJ???????J~...........		";
	cout << "\n\t                  .........!77777777777777777^...77777777777777777?^.........		";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t                  .........J55555555555555555!..:555555555555555555^.........		";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?JJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........		";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77?YPGG5????????J~..:??????????????????^.........		";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........		";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................		";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.												";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.													";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.														";
	cout << "\n\t......:5B57																		";
	cout << "\n\t........																			";
	cout << "\n\t...																				";
}
void Menu::pic3() {
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                   .:^!:           ";
	cout << "\n\t                                                          ..:...^PB#&@&~           ";
	cout << "\n\t                                                      ..!YPB#&^^^?@@@@G^:          ";
	cout << "\n\t                                                ^!JPG:..^@@@@@?...&@@@@P..         ";
	cout << "\n\t                                      .:~?5!...G@@@@&:..?@@@@@^..^@@@@@?..         ";
	cout << "\n\t                             .:~7Y...^@@@@@J...&@@@@G...P@@@@&...?@@@@@^...        ";
	cout << "\n\t                    ..^7^   P@@@@&:..7@@@@@^..^@@@@@?...&@@@@G...P@&#G?            ";
	cout << "\n\t           .~7?^:.^&@@@@BJY!&@@@@G...P@@@@&:..?@@@@@~..^@@&#G^                     ";
	cout << "\n\t         ^PBBBBJ..7@@&##&&&&@@@@@?...&@@@@B...G@@&#5.   .                          ";
	cout << "\n\t        ^BBBBBBG^~P#BGGB#G7J@@@@@~..^@@@&#!   :.                                   ";
	cout << "\n\t       !BBBBBBBBGBBGGB#G:..P@@@&B.. .^.                                            ";
	cout << "\n\t      7BBBBBBBBBBBBB&@@@Y~:^^.                                                     ";
	cout << "\n\t..  ^5BBBBBBBBBBBBG&@@@@&GG7   :~~~~~    ^~~~~~    ^~~~~^    ~~~~~^   .~~~~~:      ";
	cout << "\n\t##GPBBBBBBBBBBBBBBBG#@@@@@G^..~@@@@@B...7@@@@@5...J@@@@@J...P@@@@@7...B@@@@@^      ";
	cout << "\n\t&#GBBBBBBBBBBBBBBBBJB@@@@&:..:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@7.      ";
	cout << "\n\t&&#GBBBBBBBBBBBBBB5B@@@@@~...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..      ";
	cout << "\n\t!#&#GBBBBBBBBBBBG!Y@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@#...^@@@@@B...      ";
	cout << "\n\t.~B&&BBBBBBBGPY~ .@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:      ";
	cout << "\n\t..:Y&#P~.:..      ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:      ";
	cout << "\n\t....:.            ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........      ";
	cout << "\n\t.                 ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........      ";
	cout << "\n\t                  ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB7...........      ";
	cout << "\n\t                  ..........:??????????????J?JJJJ?J?JJJJJ???????J~...........      ";
	cout << "\n\t                  .........!77777777777777777^...77777777777777777?^.........      ";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t                  .........J55555555555555555!..:555555555555555555^.........      ";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?JJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........      ";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77?JPGG5????????J~..:??????????????????^.........      ";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................      ";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.                                                ";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.                                                  ";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.                                                     ";
	cout << "\n\t......:5B57                                                                        ";
	cout << "\n\t........                                                                           ";
	cout << "\n\t...                                                                                ";
}
void Menu::pic4() {
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                             ..:    JBB&&G         ";
	cout << "\n\t                                                 .:~!?^ ..Y&@@@&:..!@@@@@7.        ";
	cout << "\n\t                                       ^?YPG5...?@@@@@~..:@@@@@5...G@@@@&:.        ";
	cout << "\n\t                      ..:.   !B#&&&:..~@@@@@Y...#@@@@#...J@@@@@^..^@@@@@Y..        ";
	cout << "\n\t           ^!?YJ::.!&@@@@5~~:&@@@@G...5@@@@@:..~@@@@@?...#@@@@B...Y@@@@@^...       ";
	cout << "\n\t         .5BBBBB~..B@@&#&&&&#@@@@@!..:&@@@@P...P@@@@&:..!@@@@@!...5BPY?~           ";
	cout << "\n\t        ^GBBBBBBY^?#BBGB#&BY&@@@@#...?@@@@@~..^@@@@&J . ^77~:.                     ";
	cout << "\n\t       7BBBBBBBBBBBGGGBB7^.~@@@@@J...G&&BBJ   .:..                                 ";
	cout << "\n\t     :5BBBBBBBBBBBBB#&@@?:.!PYJ!~                                                  ";
	cout << "\n\tP57~5BBBBBBBBBBBBBG&@@@@&P5^   .^~~~~    ^~~~~~    ^~~~~^    ~~~~~^   .~~~~~:      ";
	cout << "\n\t&#BBBBBBBBBBBBBBBBBG&@@@@@G!..~@@@@@B...7@@@@@5...J@@@@@J...P@@@@@7...B@@@@@^      ";
	cout << "\n\t&#GBBBBBBBBBBBBBBBB~#@@@@&^..:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@7.      ";
	cout << "\n\t&&#GBBBBBBBBBBBBBG!G@@@@@~...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..      ";
	cout << "\n\t!&&#GGBBBBBBBBBG7.J@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@#...^@@@@@B...      ";
	cout << "\n\t.~#&&#G5PPP5Y7:  .@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:      ";
	cout << "\n\t..:JJ~            ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:      ";
	cout << "\n\t..                ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........      ";
	cout << "\n\t                  ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........      ";
	cout << "\n\t                  ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB7...........      ";
	cout << "\n\t                  ..........:??????????????J?JJJJ?J?JJJJJ???????J~...........      ";
	cout << "\n\t                  .........!77777777777777777^...77777777777777777?^.........      ";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t                  .........J55555555555555555!..:555555555555555555^.........      ";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?JJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........      ";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77?JPGG5????????J~..:??????????????????^.........      ";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................      ";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.                                                ";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.                                                  ";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.                                                     ";
	cout << "\n\t......:5B57                                                                        ";
	cout << "\n\t........                                                                           ";
	cout << "\n\t...                                                                                ";
}
void Menu::pic5() {
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                   ...:.   .7J?YP^ ..Y&&&&&:       ";
	cout << "\n\t                              .:~!~!.  .YPG##P...!@@@@@J...B@@@@@:..~@@@@@Y.       ";
	cout << "\n\t           :7JPPY^:.7#&&&@7...&@@@@#:..?@@@@@7...&@@@@#...7@@@@@7...#@@@@&..       ";
	cout << "\n\t          YBBBBBG:.:@@@&&&##BG@@@@@~..:&@@@@B...J@@@@@!..:&@@@@B...?@@@@@!..       ";
	cout << "\n\t        ^GBBBBBBG!!5#BBG#&&#B@@@@@P...Y@@@@@~..:@@@@@G...Y@@@@@~..:@@@@@B...       ";
	cout << "\n\t      .JBBBBBBBBBBBBGGGB5?~:G@@@@@:..~@@@@@P...P@@@@@^..:B&&BBJ   :777!^.          ";
	cout << "\n\t~!. :?GBBBBBBBBBBBBB#&@@?..~&&&&#7   75JJJ!    ::...                               ";
	cout << "\n\t&#BGBBBBBBBBBBBBBBG&@@@@&5?:.. ^~~~~~    :^^^^~    ^~~~~^    ~~~~~^   .~~~~~:      ";
	cout << "\n\t&BGBBBBBBBBBBBBBBBBG&@@@&&G?..~@@@@@B...7@@@@@5...J@@@@@J...P@@@@@7...B@@@@@^      ";
	cout << "\n\t&&GBBBBBBBBBBBBBBBP^#@@@@&^..:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@7.      ";
	cout << "\n\t&&#GBBBBBBBBBBBBBY:G@@@@@~...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..      ";
	cout << "\n\t!&&#BBBBBBBBBBP?. J@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@#...^@@@@@B...      ";
	cout << "\n\t.~B#G?~!7J7!~.   :@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:      ";
	cout << "\n\t....              ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:      ";
	cout << "\n\t                  ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........      ";
	cout << "\n\t                  ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........      ";
	cout << "\n\t                  ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB7...........      ";
	cout << "\n\t                  ..........:??????????????J?JJJJ?J?JJJJJ???????J~...........      ";
	cout << "\n\t                  .........!77777777777777777^...77777777777777777?^.........      ";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t                  .........J55555555555555555!..:555555555555555555^.........      ";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?JJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........      ";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77?JPGG5????????J~..:??????????????????^.........      ";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................      ";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.                                                ";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.                                                  ";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.                                                     ";
	cout << "\n\t......:5B57                                                                        ";
	cout << "\n\t........                                                                           ";
	cout << "\n\t...                                                                                ";
}
void Menu::pic6() {
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t                                                                                   ";
	cout << "\n\t           .75PGGJ::.J#####^  .P####B...:B####5...~#&&&&J...J&&&&&!...G&&&&&.      ";
	cout << "\n\t          7GBBBBBY..7@@@@@&GP!Y@@@@@7...B@@@@@~..^&@@@@#:..!@@@@@P...J@@@@@?.      ";
	cout << "\n\t        ~GBBBBBBB5~7B#BBB&&&&&@@@@@5...Y@@@@@7...B@@@@@^..:&@@@@#...!@@@@@P..      ";
	cout << "\n\t      ~PBBBBBBBBBBBBGGGBGP577@@@@@#...!@@@@@5...5@@@@@7...B@@@@@^..:&@@@@#...      ";
	cout << "\n\t#BP!YGBBBBBBBBBBBBBB#&&@Y...#@@@@&:..^@@@@@B...7@@@@@Y...5@@@@@!...B@@@@&:...      ";
	cout << "\n\t&BBBBBBBBBBBBBBBBBG&@@@@&J!^??7PBY!7!~??7GB?!!~^~~~Y5!!!~^~~~5Y!!7~~~^!5J!!7:      ";
	cout << "\n\t&#GBBBBBBBBBBBBBBBBG&@@@&BB7..^@@@@@B...!@@@@@5...J@@@@@J...5@@@@@7...G@@@@@^      ";
	cout << "\n\t&&GBBBBBBBBBBBBBBBJ:#@@@@&^:.:&@@@@#:..^@@@@@B...!@@@@@P...?@@@@@Y...5@@@@@7.      ";
	cout << "\n\t&&#GBBBBBBBBBBBBP!.G@@@@@!...B@@@@@^..:&@@@@&:..:&@@@@#...~@@@@@G...7@@@@@5..      ";
	cout << "\n\t!&&#BGGBBBBBG5?:  J@@@@@?...5@@@@@!...G@@@@@^...#@@@@&:..:&@@@@#...^@@@@@B...      ";
	cout << "\n\t.~7~. ..:.:.     :@@@@@B^^^7@@@@@P^^^J@@@@@Y:^^5@@@@@?^^^G@@@@@7^^^#@@@@&~^^:      ";
	cout << "\n\t                  ^^^^^^^^^^^::::::::^^^^^^:^^^^^^^^::^::^:::::::^^^^^^^^^^^:      ";
	cout << "\n\t                  ..........:GGGGGGGGGGYJP5P555Y5YG5GY5GGGGGGGGGB7...........      ";
	cout << "\n\t                  ..........^@@@@@@@@@@JY5JP5JY5YJG7BY5@@@@@@@@@@5...........      ";
	cout << "\n\t                  ..........:GBBBBBBBBBGBGGPGGGGGGPGPPPBBBBBBBBBB7...........      ";
	cout << "\n\t                  ..........:??????????????J?JJJJ?J?JJJJJ???????J~...........      ";
	cout << "\n\t                  .........!77777777777777777^...77777777777777777?^.........      ";
	cout << "\n\t                  .........7JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t                  .........J55555555555555555!..:555555555555555555^.........      ";
	cout << "\n\t                  .........7JJJ??JJJJJJJJJJJJ~..:?JJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t           .^!7?7!!~:......?JJJJJJJJJJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t        ^5GBBBBBBBBBGY~....YPPPPPPPPPPPPPPPPP!..:5PPPPPPPPPPPPPPPPP^.........      ";
	cout << "\n\t   :~77PBBBBBBBBBBBBBBBY^:^!77?JPGG5????????J~..:??????????????????^.........      ";
	cout << "\n\t...P&&BBBBBBBBBBBBBBBBBBGGBBBBBB&&&&PJJJJJJJJ~..:JJJJJJJJJJJJJJJJJJ^.........      ";
	cout << "\n\t...7&&BBBBBBBBBBBBBBBBBBBBBBBBG55YJ^.........................................      ";
	cout << "\n\t....G&#GBBBBBBBBBBBBBBBBBBBBBBGGPJ.                                                ";
	cout << "\n\t....^#&#GGGBBBBBBBBBBBBBBBBBBBP7.                                                  ";
	cout << "\n\t.....^B&&##Y~~!?YPPGGGGGP5Y?~.                                                     ";
	cout << "\n\t......:5B57                                                                        ";
	cout << "\n\t........                                                                           ";
	cout << "\n\t...                                                                                ";
}
void Menu::logo() {
	SetConsoleTextAttribute(cl, 6);
	Sleep(30);
	cout << "\n\t                                                                                                      ..   .J#@@~@@J# ";
	Sleep(30);
	cout << "\n\t                                                                                                  .JB@@@&G!.  ~PP.@@@ ";
	Sleep(30);
	cout << "\n\t                                                                                          7G#&@&Y^  .7G@@@@@&Y^ .@@PJ ";
	Sleep(30);
	cout << "\n\t                                                                                 ~YB#&B?:  :Y#@@@@@B?.  ^5#BGJ!.^^^   ";
	Sleep(30);
	cout << "\n\t                                                                        ^7YG#G!. .~P&@@@@&P~. .!G&&#P?.               ";
	Sleep(30);
	cout << "\n\t                                                               .~7YG5^  .7#@@@@@#J:  .?B@@&#Y:                        ";
	Sleep(30);
	cout << "\n\t                                                      .:^!J?:  :Y&@@@@@B7.  ^5&@@@&P^                                 ";
	Sleep(30);
	cout << "\n\t                                              ..^7!.  :5&@@@@&P~  .!G&@@@@P^   ..                                     ";
	Sleep(30);
	cout << "\n\t                                             ^P&@@@@#J:  .?B@@@@@G^   ^^.                                             ";
	Sleep(30);
	cout << "\n\t                                             7.  ^Y&@@@@&P^  .~!^..                                                   ";
	Sleep(30);
	cout << "\n\t                                             #@&5:  .7J!^:.                                                           ";
	Sleep(30);
	cout << "\n\t                                             .Y7~..    .....    .....     ....     ....     .....    .....     ...... ";
	Sleep(30);
	cout << "\n\t                                             G@@G:  ?&@@@#~  ~&@@@&7  ^B@@@@Y  .P@@@@G.  J&@@@B^  !&@@@&!  ^B@@@&J    ";
	Sleep(30);
	cout << "\n\t                                             .  J@@@@#~  !&@@@&?  ^B@@@@5. .P@@@@G: .Y@@@@#~  7&@@@&?  ~#@@@@Y. :G@@J ";
	Sleep(30);
	cout << "\n\t                                               .^^:^:    ^^:::    ^^^:^    :^^:^.   .^^:^.   .^^:::    ^^^:^    :^^^. ";
	Sleep(30);
	cout << "\n\t                                             !YJ?????JJJJ?????JJJJ?????JJJJ??????JJJJ?????JJJJ?????JJJJ?????JJJJ????: ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@BJG@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.   :J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.      .~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.          .7G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.              :?#@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                  ~5&@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                    :@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.                 ^5&@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.             :?B@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.         .!G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@.     .~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@:  :J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@&B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
	Sleep(30);
	cout << "\n\t                                             G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@? ";
	Sleep(30);
	cout << "\n\t                                              .P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&J   ";
	Sleep(30);
	cout << "\n\t                                                 .::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.     ";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 8);
	for (int i = 0; i < 21; i++) {
		cout << i * 5 << "%  LOADING ...";
		cout.flush();
		Sleep(50);
		if (i == 0 || i == 1) cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		else if (i == 20) cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		else cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
	system("cls");
	SetConsoleTextAttribute(cl, 4);
	for (short i = 30; i > 1; i--) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, i });
		cout << endl;
		cout << "\t\t\t\t\t\t\t ______    ________  ___   __    ______   ___ __ __   ________      " << endl;
		cout << "\t\t\t\t\t\t\t/_____/\\  /_______/\\/__/\\ /__/\\ /_____/\\ /__//_//_/\\ /_______/\\     " << endl;
		cout << "\t\t\t\t\t\t\t\\:::__\\/  \\__.::._\\/\\::\\_\\\\  \\ \\\\::::_\\/_\\::\\| \\| \\ \\\\::: _  \\ \\    " << endl;
		cout << "\t\t\t\t\t\t\t \\:\\ \\  __   \\::\\ \\  \\:. `-\\  \\ \\\\:\\/___/\\\\:.      \\ \\\\::(_)  \\ \\   " << endl;
		cout << "\t\t\t\t\t\t\t  \\:\\ \\/_/\\  _\\::\\ \\__\\:. _    \\ \\\\::___\\/_\\:.\\-/\\  \\ \\\\:: __  \\ \\  " << endl;
		cout << "\t\t\t\t\t\t\t   \\:\\_\\ \\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\\\:\\____/\\\\. \\  \\  \\ \\\\:.\\ \\  \\ \\ " << endl;
		cout << "\t\t\t\t\t\t\t    \\_____\\/\\________\\/ \\__\\/ \\__\\/ \\_____\\/ \\__\\/ \\__\\/ \\__\\/\\__\\/ ";
		Sleep(5);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                                                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
}
void Menu::intro() {
	SetConsoleCursorPosition(cl, { 115, 18 });
	cout << "Sinh Vien Thuc Hien: ";
	SetConsoleCursorPosition(cl, { 115, 20 });
	cout << "\t-  HUYNH VAN LOC \t\tLop:\t21T_DT";
	SetConsoleCursorPosition(cl, { 115, 22 });
	cout << "\t-  NGUYEN VAN HUY\t\tLop:\t21T_DT";
	SetConsoleCursorPosition(cl, { 115, 25 });
	cout << "Giang Vien Huong Dan: ";
	SetConsoleCursorPosition(cl, { 115, 27 });
	cout << "\t-  VO DUC HOANG  \t\tKhoa:   CNTT";
	welcome();
	qlrcp();
	for (int i = 0; i < 51; i++) {
		if (i % 2 == 0) {
			if (i < 42) {
				SetConsoleTextAttribute(cl, 8);
				SetConsoleCursorPosition(cl, { 135, 37 });
				cout << i * 5 / 2 << "%  LOADING ...";
				Sleep(150);
				SetConsoleTextAttribute(cl, 6);
			}
			else {
				SetConsoleTextAttribute(cl, 8);
				SetConsoleCursorPosition(cl, { 135, 37 });
				cout << "                 ";
				Sleep(75);
				SetConsoleCursorPosition(cl, { 135, 37 });
				cout << "100%  LOADING ...";
				Sleep(75);
				SetConsoleTextAttribute(cl, 6);
			}
		}
		if (i % 12 == 0) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic1();
		}
		else if (i % 12 == 2) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic2();
		}
		else if (i % 12 == 4) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic3();
		}
		else if (i % 12 == 6) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic4();
		}
		else if (i % 12 == 8) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic5();
		}
		else if (i % 12 == 10) {
			SetConsoleCursorPosition(cl, { 0, 0 });
			pic6();
		}
	}
	system("cls");
	SetConsoleTextAttribute(cl, 4);
	for (short i = 30; i > 1; i--) {
		SetConsoleCursorPosition(cl, { 0, i });
		cout << endl;
		cout << "\t\t\t\t\t\t\t ______    ________  ___   __    ______   ___ __ __   ________      " << endl;
		cout << "\t\t\t\t\t\t\t/_____/\\  /_______/\\/__/\\ /__/\\ /_____/\\ /__//_//_/\\ /_______/\\     " << endl;
		cout << "\t\t\t\t\t\t\t\\:::__\\/  \\__.::._\\/\\::\\_\\\\  \\ \\\\::::_\\/_\\::\\| \\| \\ \\\\::: _  \\ \\    " << endl;
		cout << "\t\t\t\t\t\t\t \\:\\ \\  __   \\::\\ \\  \\:. `-\\  \\ \\\\:\\/___/\\\\:.      \\ \\\\::(_)  \\ \\   " << endl;
		cout << "\t\t\t\t\t\t\t  \\:\\ \\/_/\\  _\\::\\ \\__\\:. _    \\ \\\\::___\\/_\\:.\\-/\\  \\ \\\\:: __  \\ \\  " << endl;
		cout << "\t\t\t\t\t\t\t   \\:\\_\\ \\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\\\:\\____/\\\\. \\  \\  \\ \\\\:.\\ \\  \\ \\ " << endl;
		cout << "\t\t\t\t\t\t\t    \\_____\\/\\________\\/ \\__\\/ \\__\\/ \\_____\\/ \\__\\/ \\__\\/ \\__\\/\\__\\/ ";
		Sleep(1);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                                                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
	SetConsoleTextAttribute(cl, 8);
}
void Menu::cinema() {
	cout << endl;
	cout << "\t\t\t\t\t\t\t ______    ________  ___   __    ______   ___ __ __   ________      " << endl;
	cout << "\t\t\t\t\t\t\t/_____/\\  /_______/\\/__/\\ /__/\\ /_____/\\ /__//_//_/\\ /_______/\\     " << endl;
	cout << "\t\t\t\t\t\t\t\\:::__\\/  \\__.::._\\/\\::\\_\\\\  \\ \\\\::::_\\/_\\::\\| \\| \\ \\\\::: _  \\ \\    " << endl;
	cout << "\t\t\t\t\t\t\t \\:\\ \\  __   \\::\\ \\  \\:. `-\\  \\ \\\\:\\/___/\\\\:.      \\ \\\\::(_)  \\ \\   " << endl;
	cout << "\t\t\t\t\t\t\t  \\:\\ \\/_/\\  _\\::\\ \\__\\:. _    \\ \\\\::___\\/_\\:.\\-/\\  \\ \\\\:: __  \\ \\  " << endl;
	cout << "\t\t\t\t\t\t\t   \\:\\_\\ \\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\\\:\\____/\\\\. \\  \\  \\ \\\\:.\\ \\  \\ \\ " << endl;
	cout << "\t\t\t\t\t\t\t    \\_____\\/\\________\\/ \\__\\/ \\__\\/ \\_____\\/ \\__\\/ \\__\\/ \\__\\/\\__\\/ " << endl << endl;
}
void Menu::login() {
	fsst.open("Staff.txt", ios::in);
	stMng.readFile(fsst);
	fsst.close();
	fsdrt.open("Director.txt", ios::in);
	drtMng.readFile(fsdrt);
	fsdrt.close();
	fsfilm.open("Film.txt", ios::in);
	filmMng.readFile(fsfilm);
	fsfilm.close();
	fscr.open("CinemaRoom.txt", ios::in);
	cnmMng.readFile(fscr);
	fscr.close();
	fsscd.open("Schedule.txt", ios::in);
	scdMng.readFile(fsscd);
	fsscd.close();
	fstk.open("Ticket.txt", ios::in);
	tkMng.readFile(fstk);
	fstk.close();
	fsslr.open("Salary.txt", ios::in);
	stMng.readSalaryFile(fsslr);
	fsslr.close();
	int cnt = 0;
	intro();
	system("cls");
	do {
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 7);
		cout << endl;
		cout << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n" << left << setw(70) << " " << "|";
		cout << left << setw(12) << " " << "DANG NHAP";
		cout << setw(12) << " " << "|";
		cout << "\n" << left << setw(70) << " ";
		for (int i = 0; i < 35; i++) cout << "-";
		cout << endl;
		string account, password;
		char pas, pass; int c = 0;
		cout << "\n\t\t\t\t\t\t\t\t" << left << setw(16) << "TEN DANG NHAP" << ":   ";
		getline(cin, account);
		cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(16) << "MAT KHAU" << ":   ";
		while (true) {
			pas = _getch();
			if (pas == 13) break;
			if (pas == 8 && c > 0) {
				cout << "\b \b";
				password.resize(password.size() - 1);
				c--;
			}
			else if (pas == 8 && c == 0) {}
			else {
				c++;
				pass = pas;
				password.push_back(pass);
				cout << "*";
			}
		}
		for (int i = 0; i < stMng.getLength(); i++) {
			if (account.compare(stMng.operator[](i).getAccount()) == 0 && password.compare(stMng.operator[](i).getPassword()) == 0) {
				cnt = 1;
			}
		}
		if (cnt != 1) {
			for (int i = 0; i < drtMng.getLength(); i++) {
				if (account.compare(drtMng.operator[](i).getAccount()) == 0 && password.compare(drtMng.operator[](i).getPassword()) == 0) {
					cnt = 2;
				}
			}
		}
		if (cnt == 0) {
			int x;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << endl;
				cout << left << setw(70) << " ";
				for (int i = 0; i < 35; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				cout << left << setw(12) << " " << "DANG NHAP";
				cout << setw(12) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 35; i++) cout << "-";
				cout << endl;
				cout << "\n\t\t\t\t\t\t\t\t" << left << setw(16) << "TEN DANG NHAP" << ":   ";
				cout << "\n\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t" << left << setw(16) << "MAT KHAU" << ":   ";
				cout << "\n\n\t\t\t\t\t\t\t\t\tTAI KHOAN KHONG HOP LE.";
				cout << "\n\n\t\t\t\t\t\t\t\t1. Dang nhap Lai.";
				cout << "\t\t  2. Thoat";
				cout << "\n\t\t\t\t\t\t\t\t";
				x = getInt();
				if (x == 2) return;
				else if (x != 1) {
					cout << "\t\t\t\t\t\t\t\t\tLua chon khong hop le!\n";
					system("pause");
				}
			} while (x != 1);
		}
		system("cls");
	} while (cnt == 0);
	if (cnt == 1) {
		stMenu();
	}
	else if (cnt == 2) {
		drtMenu();
	}
}
void Menu::stMenu() {
	int opt = 0;
	do {
		system("cls");
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 14);
		cout << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		Sleep(50);
		cout << "\n" << left << setw(70) << " " << "|";
		Sleep(50);
		cout << left << setw(14) << " " << "MENU";
		Sleep(50);
		cout << setw(15) << " " << "|";
		Sleep(50);
		cout << "\n" << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\n\t\t\t\t\t\t\t\t";
		Sleep(50);
		SetConsoleTextAttribute(cl, 7);
		for (int i = 0; i < 42; i++) cout << "-"; cout << "\n";
		cout << "\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 1. Quan li phim" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 2. Quan li phong chieu" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 3. Quan li lich chieu" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 4. Quan li hoa don" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 0. Thoat" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		for (int i = 0; i < 42; i++) cout << "-";
		Sleep(50);
		cout << "\n\n\t\t\t\t\t\t\t\t\t**Nhap lua chon: ";
		opt = getInt();
		switch (opt) {
		case (1): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI PHIM";
				cout << setw(20) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim phim theo ten";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Tim phim theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Xoa phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Cap nhat phim";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				tmp = getInt();
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM PHIM MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Film film = filmMng.setFilmInfor();
					if (film.getId() != "null") {
						filmMng.add(film);
						cout << "\t\t\t\t\t\t\t\t\tPhim da duoc them.\n"; system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH PHIM CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					filmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***TIM PHIM THEO TEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string name;
					cout << "\t\t\t\t\t\t\tNhap ten phim: ";
					getline(cin, name);
					filmMng.findByName(name);
					system("pause");
				}
				else if (tmp == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***TIM PHIM THEO MA***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phim: ";
					getline(cin, id);
					if (filmMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phim phu hop.\n";
					}
					else {
						cout << "\n\t\t\t\t\t\t\t\t\t<<PHIM CO MA TREN LA>>\n\n";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "\t              |                               |                    |                       |                    |                          |                ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "    Ma phim   |          Ten phim             |     Dao dien       |    Dien vien chinh    |      Quoc gia      |        The loai          |   Thoi gian    ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "              |                               |                    |                       |                    |                          |                ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
						SetConsoleTextAttribute(cl, 7);
						filmMng.findById(id)->writeData();
						cout << "\t";
						for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA PHIM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phim can xoa: ";
					getline(cin, id);
					if (filmMng.findById(id) != nullptr) {
						SetConsoleTextAttribute(cl, 4);
						cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI CAC PHIM BI XOA CUNG SE DUOC XOA TRONG LICH CHIEU\n";
						SetConsoleTextAttribute(cl, 7);
						cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; idel = getInt();
						if (idel == 1) {
							filmMng.del(id);
							scdMng.deleteByFilm(id);
							cout << "\t\t\t\t\t\t\tPhim co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else if (idel == 2) {}
						else {
							cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
							system("pause");
						}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phim phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT PHIM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					filmMng.update();
				}
				else if (tmp == 7) {
					fsfilm.open("Film.txt", ios::out | ios::trunc);
					filmMng.writeFile(fsfilm);
					fsfilm.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					int test, iscd = 0;
					while (iscd < scdMng.getLength()) {
						test = 0;
						for (int ifilm = 0; ifilm < filmMng.getLength(); ifilm++) {
							if (scdMng.operator[](iscd).getFilmId().compare(filmMng.operator[](ifilm).getId()) == 0) {
								test = 1;
							}
						}
						if (test == 0) {
							scdMng.del(scdMng.operator[](iscd).getId());
							iscd--;
						}
						iscd++;
					}
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLuu chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (2): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI PHONG CHIEU";
				cout << setw(13) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim phong chieu theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Cap nhat phong chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				tmp = getInt();
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM PHONG CHIEU MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					CinemaRoom cM = cnmMng.setCinemaRoomInfor();
					if (cM.getId() != "null") {
						cnmMng.add(cM);
						cout << "\t\t\t\t\t\t\tPhong chieu da duoc them.\n"; system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH PHONG CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					cnmMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***TIM PHONG CHIEU THEO MA***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phong chieu: ";
					getline(cin, id);
					if (cnmMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phong chieu phu hop.\n";
					}
					else {
						cout << "\n\t\t\t\t\t\t\t\t\t<<PHONG CHIEU CO MA TREN LA>>\n\n";
						cout << "\t\t\t\t\t\t";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "                  |               |              |              |              ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "  Ma phong chieu  |  So hang ghe  |  So cot ghe  |  Chat luong  |  Tinh trang  ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
						SetConsoleTextAttribute(cl, 0xF0 | 0x70);
						cout << "                  |               |              |              |              ";
						SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
						SetConsoleTextAttribute(cl, 7);
						cnmMng.findById(id)->writeData();
						cout << "\t\t\t\t\t\t";
						for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
					}
					system("pause");
				}
				else if (tmp == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA PHONG CHIEU***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma phong chieu can xoa: ";
					getline(cin, id);
					if (cnmMng.findById(id) != nullptr) {
						SetConsoleTextAttribute(cl, 4);
						cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI CAC PHONG CHIEU BI XOA CUNG SE DUOC XOA TRONG LICH CHIEU\n";
						SetConsoleTextAttribute(cl, 7);
						cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; idel = getInt();
						if (idel == 1) {
							cnmMng.del(id);
							scdMng.deleteByRoom(id);
							cout << "\t\t\t\t\t\t\tPhong chieu co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else if (idel != 0) {
							cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay phong chieu phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT PHONG CHIEU***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id = cnmMng.update();
					scdMng.deleteByRoom(id);
				}
				else if (tmp == 6) {
					fscr.open("CinemaRoom.txt", ios::out | ios::trunc);
					cnmMng.writeFile(fscr);
					fscr.close();
					cout << "\t\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					int test, iscd = 0;
					while (iscd < scdMng.getLength()) {
						test = 0;
						if (cnmMng.findById(scdMng.operator[](iscd).getCinemaRoomId()) != nullptr && cnmMng.findById(scdMng.operator[](iscd).getCinemaRoomId())->getStatus() != "bad") {
							test = 1;
						}
						if (test == 0) {
							scdMng.del(scdMng.operator[](iscd).getId());
							iscd--;
						}
						iscd++;
					}
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (3): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI LICH CHIEU";
				cout << setw(14) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Them lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Tim lich chieu theo ma";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa lich chieu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay lai menu";
				cout << "\n\n\t\t\t\t\t\t\t\t";
				Sleep(50);
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				tmp = getInt();
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM LICH CHIEU MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Schedule tmp = scdMng.setScheduleInfor();
					if (tmp.getId() == "null") {}
					else {
						scdMng.add(tmp);
						CinemaRoom* room = cnmMng.findById(tmp.getCinemaRoomId());
						scdMng.findById(tmp.getId())->createSeat(room);
						cout << "\t\t\t\t\t\t\tLich chieu moi da duoc them.\n";
						system("pause");
					}
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH LICH CHIEU TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					scdMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma lich chieu: ";
					getline(cin, id);
					if (scdMng.findById(id) == nullptr) {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay lich chieu phu hop.\n";
					}
					else {
						system("cls");
						scdMng.findById(id)->showSeatStatus();
					}
					system("pause");
				}
				else if (tmp == 4) {
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma lich chieu can xoa: ";
					getline(cin, id);
					if (scdMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; idel = getInt();
						if (idel == 1) {
							scdMng.del(id);
							cout << "\t\t\t\t\t\t\tLich chieu co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else if (idel != 1) {
							cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay lich chieu phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 5) {
					fsscd.open("Schedule.txt", ios::out | ios::trunc);
					scdMng.writeFile(fsscd);
					fsscd.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (4): {
			int tmp = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI HOA DON";
				cout << setw(17) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xuat hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem danh sach hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Xuat doanh thu theo thoi gian";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xuat doanh thu theo nhan vien";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Xuat tong doanh thu";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xoa hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Xuat doanh thu theo nam tung nhan vien";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t8. Xem chi tiet hoa don";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t9. Xac nhan thay doi";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Quay Lai menu";
				cout << "\n\n\t\t\t\t\t\t\t\t";
				Sleep(50);
				for (int i = 0; i < 55; i++) cout << "*";
				Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				tmp = getInt();
				if (tmp == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM HOA DON MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Ticket t = tkMng.setTicketInfor();
					if (t.getId() == "null") break;
					tkMng.add(t);
					Ticket* tt = tkMng.findById(t.getId());
					int check = 0;
					string scheduleId;
					do {
						system("cls");
						cout << "\n";
						scdMng.write();
						cout << "\n\t\t\t\t\t\t\tNhap ma lich chieu: "; 
						getline(cin, scheduleId);
						if (scdMng.findById(scheduleId) == nullptr) {
							do {
								cout << "\t\t\t\t\t\t\t\tKhong tim thay lich chieu!. Lua chon";
								cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
								cout << "\t\t\t2. Thoat";
								cout << "\n\t\t\t\t\t\t\t";
								check = getInt();
								if (check != 1 && check != 2) {
									cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
									system("pause");
								}
							} while (check != 1 && check != 2);
						}
						else check = 3;
					} while (check == 1 || check == 0);
					if (check == 2) break;
					tt->setScheduleId(scheduleId);
					check = 0;
					do {
						string seatId;
						system("cls");
						scdMng.findById(scheduleId)->showSeatStatus();
						cout << "\n\t\t\t\t\t\t\tChon ma ghe: "; 
						getline(cin, seatId);
						if (scdMng.findById(scheduleId)->getSeat(seatId) == nullptr) {
							do {
								cout << "\t\t\t\t\t\t\t\tMa khong phu hop!. Lua chon";
								cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
								cout << "\t\t\t2. Thoat";
								cout << "\n\t\t\t\t\t\t\t";
								check = getInt();
								if (check != 1 && check != 2) {
									cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
									system("pause");
								}
							} while (check != 1 && check != 2);
						}
						else if (scdMng.findById(scheduleId)->getSeat(seatId)->getChecked() == true) {
							cout << "\t\t\t\t\t\t\t\tCho nay da duoc dat!" << endl;
							system("pause");
							check = 1;
						}
						else {
							check = 3;
							if (scdMng.findById(scheduleId)->getSeat(seatId)->getVip()) {
								tt->addSeat(seatId, true);
							}
							else {
								tt->addSeat(seatId, false);
							}
							if (scdMng.findById(scheduleId)->getSeat(seatId) != nullptr) {
								scdMng.findById(scheduleId)->getSeat(seatId)->setChecked(true);
							}
							do {
								cout << "\t\t\t\t\t\t\t\tXac nhan hoa don?";
								cout << "\n\t\t\t\t\t\t\t1. Chon tiep vi tri";
								cout << "\t\t\t2. Xac nhan";
								cout << "\n\t\t\t\t\t\t\t";
								check = getInt();
								if (check != 1 && check != 2) {
									cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
									system("pause");
								}
							} while (check != 1 && check != 2);
						}
					} while (check == 1 || check == 0);
					cout << "\t\t\t\t\t\t\tDa ban 1 hoa don moi.\n";
					system("pause");
				}
				else if (tmp == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH HOA DON DA BAN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					tkMng.write();
					system("pause");
				}
				else if (tmp == 3) {
					int date;
					int month;
					int year;
					do {
						try {
							cout << "\t\t\t\t\t\t\tNhap ngay bat dau: ";
							date = getInt();
							cout << "\t\t\t\t\t\t\tNhap thang bat dau: ";
							month = getInt();
							cout << "\t\t\t\t\t\t\tNhap nam bat dau: ";
							year = getInt();
							checktime(date, month, year);
							break;
						}
						catch (Error error) {
							error.getMessage();
						}
					} while (true);
					Time t1(date, month, year);
					do {
						try {
							cout << "\t\t\t\t\t\t\tNhap ngay ket thuc: ";
							date = getInt();
							cout << "\t\t\t\t\t\t\tNhap thang ket thuc: ";
							month = getInt();
							cout << "\t\t\t\t\t\t\tNhap nam ket thuc: ";
							year = getInt();
							checktime(date, month, year);
							break;
						}
						catch (Error error) {
							error.getMessage();
						}
					} while (true);
					Time t2(date, month, year);
					cout << "\n\n\t\t\t\t\t\t\t>> DOANH THU TRONG THOI GIAN TREN LA: ";
					SetConsoleTextAttribute(cl, 10);
					cout << tkMng.getRevenue(t1, t2) << endl;
					SetConsoleTextAttribute(cl, 7);
					system("pause");
				}
				else if (tmp == 4) {
					int opt4 = 0;
					string id;
					do {
						cout << "\t\t\t\t\t\t\tNhap ma nhan vien: ";
						getline(cin, id);
						if (stMng.findById(id) == nullptr) {
							do {
								cout << "\t\t\t\t\t\t\t\tKhong tim thay nhan vien phu hop!. Lua chon";
								cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
								cout << "\t\t\t2. Thoat";
								cout << "\n\t\t\t\t\t\t\t";
								opt4 = getInt();
								if (opt4 != 1 && opt4 != 2) {
									cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
									system("pause");
								}
							} while (opt4 != 1 && opt4 != 2);
						}
						else opt4 = 3;
					} while (opt4 == 1 || opt4 == 0);
					if (opt4 != 3) {}
					else {
						cout << "\n\n\t\t\t\t\t\t\t>> DOANH THU DO NHAN VIEN TREN TAO RA LA: ";
						SetConsoleTextAttribute(cl, 10);
						cout << tkMng.getRevenue(id) << endl;
						SetConsoleTextAttribute(cl, 7);
						system("pause");
					}
				}
				else if (tmp == 5) {
					cout << "\n\n\t\t\t\t\t\t\t>> TONG DOANH THU CUA RAP LA: ";
					SetConsoleTextAttribute(cl, 10);
					cout << tkMng.getRevenue() << endl;
					SetConsoleTextAttribute(cl, 7);
					system("pause");
				}
				else if (tmp == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***XOA HOA DON***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\n\t\t\t\t\t\t\tNhap ma hoa don can xoa: ";
					getline(cin, id);
					if (tkMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; idel = getInt();
						if (idel == 1) {
							tkMng.del(id);
							cout << "\t\t\t\t\t\t\tHoa don co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else if (idel != 0) {
							cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay hoa phu hop.\n";
						system("pause");
					}
				}
				else if (tmp == 7) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DOANH THU CHI TIET THEO NAM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					int year;
					do {
						try {
							cout << "\t\t\t\t\t\t\tNhap nam can thong ke doanh thu: ";
							year = getInt();
							checktime(1, 1, year);
							break;
						}
						catch (Error error) {
							error.getMessage();
						}
					} while (true);
					SetConsoleTextAttribute(cl, 10);
					cout << "\n\n\t\t\t\t\t\t\t\t<<<DOANH THU CHI TIET NAM " << year << " LA>>>\n";
					SetConsoleTextAttribute(cl, 7);
					tkMng.getRevenueY(year);
					system("pause");
				}
				else if (tmp == 8) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\n\t\t\t\t\t\t\tNhap ma hoa don can xem: ";
					getline(cin, id);
					if (tkMng.findById(id) != nullptr) {
						Ticket* tk = tkMng.findById(id);
						SetConsoleTextAttribute(cl, 3);
						cout << "\n\t\t\t\t\t\t\t\t\t***CHI TIET HOA DON TREN LA***";
						SetConsoleTextAttribute(cl, 0xA);
						SetConsoleCP(437);
						SetConsoleOutputCP(437);
						cout << "\n\n";
						cout << "\t\t\t\t\t" << (char)218;
						for (int i = 0; i < 81; i++) cout << (char)196;
						cout << (char)191;
						cout << "\n\t\t\t\t\t" << (char)179 << "                                   VE XEM PHIM                                   " << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tTen khach hang : " << left << setw(57) << tk->getCustomerName() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tSDT khach hang : " << left << setw(57) << tk->getCustomerPhone() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tTen phim       : " << left << setw(57) << filmMng.findById(scdMng.findById(tk->getScheduleId())->getFilmId())->getName() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tNgay chieu     : "; scdMng.findById(tk->getScheduleId())->getTime().writet();
						cout << "          Ca chieu     : " << left << setw(22) << scdMng.findById(tk->getScheduleId())->getShow() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tSo ve mua      : " << left << setw(20) << tk->getCountReg()+tk->getCountVip() << "Gia ve co ban: " << left << setw(22) << scdMng.findById(tk->getScheduleId())->getBaseCost() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tMa rap         : " << left << setw(20) << scdMng.findById(tk->getScheduleId())->getCinemaRoomId() << "Vi tri       : ";
						for (int i = 0; i < tk->getCountReg(); i++) {
							if (i != tk->getCountReg() - 1) cout << *(tk->getIdRegSeat(i)) << ",";
							else cout << *(tk->getIdRegSeat(i));
						}
						if (tk->getCountVip() != 0 && tk->getCountReg() != 0) cout << ",";
						for (int i = 0; i < tk->getCountVip(); i++) {
							if (i != tk->getCountVip() - 1) cout << *(tk->getIdVipSeat(i)) << ",";
							else cout << *(tk->getIdVipSeat(i));
						}
						SetConsoleCursorPosition(cl, { 122, 21 }); cout << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\tBap nuoc       : " << left << setw(20) << tk->getSoda_Corn() << "Tong tien    : " << left << setw(22) << tk->getCountReg()* scdMng.findById(tk->getScheduleId())->getBaseCost()+ tk->getCountVip()*(scdMng.findById(tk->getScheduleId())->getBaseCost() + 5) + 20*tk->getSoda_Corn() << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						for (int i = 0; i < 81; i++) cout << " ";
						cout << (char)179;
						cout << "\n\t\t\t\t\t" << (char)179;
						cout << "\t\t\t\t\t             Cinema, Lien chieu, Da Nang  " << (char)179;
						cout << "\n\t\t\t\t\t" << (char)192;
						for (int i = 0; i < 81; i++) cout << (char)196;
						cout << (char)217 << "\n\n\t\t\t\t\t\t";
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay hoa phu hop.\n";
					}
					SetConsoleTextAttribute(cl, 7);
					system("pause");
				}
				else if (tmp == 9) {
					fstk.open("Ticket.txt", ios::out | ios::trunc);
					tkMng.writeFile(fstk);
					fstk.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (tmp != 0) {
					cout << "\t\t\t\t\t\t\tLua chon khong phu hop. Moi chon lai.\n";
					system("pause");
				}
			} while (tmp != 0);
			break;
		}
		case (0): {	break; }
		default: {
			cout << "\t\t\t\t\t\t\tLua chon khong hop le.\n";
			system("pause");
			break;
		}
		}
	} while (opt != 0);
}
void Menu::drtMenu() {
	int opt = 0;
	do {
		system("cls");
		SetConsoleTextAttribute(cl, 4);
		cinema();
		SetConsoleTextAttribute(cl, 14);
		cout << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		Sleep(50);
		cout << "\n" << left << setw(70) << " " << "|";
		Sleep(50);
		cout << left << setw(14) << " " << "MENU";
		Sleep(50);
		cout << setw(15) << " " << "|";
		Sleep(50);
		cout << "\n" << left << setw(70) << " ";
		Sleep(50);
		for (int i = 0; i < 35; i++) cout << "-";
		cout << "\n\n\t\t\t\t\t\t\t\t";
		Sleep(50);
		SetConsoleTextAttribute(cl, 7);
		for (int i = 0; i < 42; i++) cout << "-"; cout << "\n";
		cout << "\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 1. Quan li nhan vien" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 2. Thong tin quan li" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		Sleep(50);
		cout << "\n\t\t\t\t\t\t\t\t|" << left << setw(40) << " 0. Thoat" << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		cout << "|" << left << setw(40) << " " << "|";
		cout << "\n\t\t\t\t\t\t\t\t";
		for (int i = 0; i < 42; i++) cout << "-";
		Sleep(50);
		cout << "\n\n\t\t\t\t\t\t\t\t\t**Nhap lua chon: ";
		opt = getInt();
		switch (opt) {
		case (1): {
			int opt1 = 0;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|";
				Sleep(50);
				cout << left << setw(14) << " " << "QUAN LI NHAN VIEN";
				cout << setw(15) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xem thong tin nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Xem thong tin nhan than"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Them nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xoa nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t5. Cap nhat thong tin nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t6. Xem luong nhan vien theo nam"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t7. Them (cap nhat) luong nhan vien"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t8. Xac nhan thay doi"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Thoat"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				opt1 = getInt();
				if (opt1 == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***DANH SACH NHAN VIEN LAM VIEC TAI RAP***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.write();
					system("pause");
				}
				else if (opt1 == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***THONG TIN NHAN THAN CUA NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.writerl();
					system("pause");
				}
				else if (opt1 == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***THEM NHAN VIEN MOI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					Staff staff = stMng.setStaff();
					if (staff.getId() != "null") {
						stMng.add(staff);
						cout << "\t\t\t\t\t\t\tNhan vien moi da duoc them.\n";
						system("pause");
					}
				}
				else if (opt1 == 4) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***XOA NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					string id;
					cout << "\t\t\t\t\t\t\tNhap ma nhan vien can xoa: ";
					getline(cin, id);
					if (stMng.findById(id) != nullptr) {
						cout << "\t\t\t\t\t\t\t\tBan co chac chan muon xoa.";
						cout << "\n\t\t\t\t\t\t\t1. Xoa.";
						cout << "\t\t\t0. Thoat.";
						cout << "\n\t\t\t\t\t\t\t";
						int idel; idel = getInt();
						if (idel == 1) {
							stMng.del(id);
							cout << "\t\t\t\t\t\t\tNhan vien co ma " << id << " da duoc xoa.\n";
							system("pause");
						}
						else if (idel != 0) {
							cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
							system("pause");
						}
						else {}
					}
					else {
						cout << "\n\t\t\t\t\t\t\tKhong tim thay nhan vien phu hop.\n";
						system("pause");
					}
				}
				else if (opt1 == 5) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT THONG TIN NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.update();
				}
				else if (opt1 == 6) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***LUONG NHAN VIEN CHI TIET THEO NAM***\n\n";
					SetConsoleTextAttribute(cl, 7);
					int year;
					cout << "\t\t\t\t\t\t\tNhap nam muon xem luong: ";
					year = getInt();
					SetConsoleTextAttribute(cl, 10);
					cout << "\t\t\t\t\t\t\t\t\t<<<TIEN LUONG DA TRA TRONG NAM " << year << " LA>>> " << endl;
					SetConsoleTextAttribute(cl, 7);
					stMng.writeSalaryY(year);
					system("pause");
				}
				else if (opt1 == 7) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***CAP NHAT LUONG NHAN VIEN***\n\n";
					SetConsoleTextAttribute(cl, 7);
					stMng.addSalary();
					system("pause");
				}
				else if (opt1 == 8) {
					fsst.open("Staff.txt", ios::out | ios::trunc);
					stMng.writeFile(fsst);
					fsst.close();
					fsslr.open("Salary.txt", ios::out | ios::trunc);
					stMng.writeSalaryFile(fsslr);
					fsslr.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt1 != 0) {
					cout << "\n\t\t\t\t\t\t\tLua chon khong hop le. Moi nhap lai.\n";
					system("pause");
				}
			} while (opt1 != 0);
			break;
		}
		case (2): {
			int opt2;
			do {
				system("cls");
				SetConsoleTextAttribute(cl, 4);
				cinema();
				SetConsoleTextAttribute(cl, 7);
				cout << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-";
				cout << "\n" << left << setw(70) << " " << "|"; Sleep(50);
				cout << left << setw(14) << " " << "THONG TIN QUAN LI";
				cout << setw(15) << " " << "|";
				cout << "\n" << left << setw(70) << " ";
				for (int i = 0; i < 48; i++) cout << "-"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t1. Xem thong tin quan li"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t2. Doi tai khoan"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t3. Doi mat khau"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t4. Xac nhan thay doi"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t0. Thoat"; Sleep(50);
				cout << "\n\n\t\t\t\t\t\t\t\t";
				for (int i = 0; i < 55; i++) cout << "*"; Sleep(50);
				cout << "\n\t\t\t\t\t\t\t>> Nhap lua chon: ";
				opt2 = getInt();
				if (opt2 == 1) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t***THONG TIN QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.write();
					system("pause");
				}
				else if (opt2 == 2) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***DOI TAI KHOAN QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.updateAc();
					system("pause");
				}
				else if (opt2 == 3) {
					system("cls");
					SetConsoleTextAttribute(cl, 4);
					cinema();
					SetConsoleTextAttribute(cl, 3);
					cout << "\n\t\t\t\t\t\t\t\t\t\t***DOI MAT KHAU QUAN LI***\n\n";
					SetConsoleTextAttribute(cl, 7);
					drtMng.updatePq();
					system("pause");
				}
				else if (opt2 == 4) {
					fsdrt.open("Director.txt", ios::out | ios::trunc);
					drtMng.writeFile(fsdrt);
					fsdrt.close();
					cout << "\t\t\t\t\t\t\tThay doi da duoc luu vao file.\n";
					system("pause");
				}
				else if (opt2 != 0) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le.\n";
					system("pause");
				}
			} while (opt2 != 0);
			break;
		}
		case (0): { break; }
		default: {
			cout << "\t\t\t\t\t\t\tLua chon khong hop le.\n";
			break;
		}
		}
	} while (opt != 0);
}