/* Предмет: Системне програмування
 * Факультет: ФІОТ
 * Група: ІТ-81
 * Роботу виконали:
 * - Ніконов Олександр
 * - Павленко Євгеній
 * - Сніжок Максим
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
