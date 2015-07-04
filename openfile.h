#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDialog>
#include <QFileSystemModel>
#include <painter.h>

namespace Ui {
class OpenFile;
}

class OpenFile : public QDialog
{
    Q_OBJECT

public:
    explicit OpenFile(QWidget *parent = 0);
    ~OpenFile();
     QString  fname;

private slots:
      void on_listView_clicked(const QModelIndex &index);
      void on_open_clicked();
      void on_treeView_clicked(const QModelIndex &index);

      void on_treeView_doubleClicked(const QModelIndex &index);

private:

    QFileSystemModel *lDir, *tDir;
    Ui::OpenFile *ui;
};

#endif // OPENFILE_H
