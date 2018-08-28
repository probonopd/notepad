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
