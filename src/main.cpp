/*
notepad - Simple text editor with tabs
Copyright (C) 2018  256Michael

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "mainwindow.hpp"
#include <QSharedMemory>
#include <iostream>
#include "notepadapp.hpp"

int main (int argc, char *argv[])
{
// 	QSharedMemory pamiec( "notepad-shared-memory" );
//     if( pamiec.create( 100000000 ) )
//     {
        NotepadApp app(argc, argv);
//         if (files != nullptr)
//             window = new MainWindow(&pamiec, files);
//         else window = new MainWindow(&pamiec);
        return app.exec();
//     }
//     else if( pamiec.attach() )
//     {
//         printf( "Podlaczono sie do istniejacego bloku pamieci. Rozmiar bloku wynosi %d.\n", pamiec.size());
// 
//         pamiec.lock();
//         auto* w = (int*) pamiec.data();
//         std::cin >> *w;
//         pamiec.unlock();
//         return 0;
//     } 
//     else
//     {
//         printf( "Nie udalo sie utworzyc bloku pamieci wspoldzielonej ani sie do niej podlaczyc.\n" );
//         std::cout <<"Tresc bledu: " << pamiec.errorString().toStdString();
//         return 1;
//     }
}
