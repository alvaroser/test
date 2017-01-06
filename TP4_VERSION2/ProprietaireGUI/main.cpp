/*
 * main.cpp
 \brief : sert a lancer lapplication QT.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#include "proprietairegui.h"
#include <QtGui>
#include <QApplication>
#include <Proprietaire.h>

int main(int argc, char *argv[]) {
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
	QApplication a(argc, argv);
	tp::Proprietaire p_proprietaire("Homer", "Simpson");
	ProprietaireGUI w(0, p_proprietaire);
	w.show();
	return a.exec();
}

