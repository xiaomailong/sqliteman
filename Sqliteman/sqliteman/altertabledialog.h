/*
For general Sqliteman copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Sqliteman
for which a new license (GPL+exception) is in place.
*/

#ifndef ALTERTABLEDIALOG_H
#define ALTERTABLEDIALOG_H

#include "database.h"
#include "tableeditordialog.h"


/*! \brief Handle alter table features.
Sqlite3 has very limited ALTER TABLE feature set, so
there is only support for "table rename" and "add column".
\TODO: There should be a way how to simulate drop
column with rename - inser select combination.
\author Petr Vanek <petr@scribus.info>
*/
class AlterTableDialog : public TableEditorDialog
{
	Q_OBJECT

	public:
		AlterTableDialog(QWidget * parent = 0, const QString & tableName = 0, const QString & schema = 0);
		~AlterTableDialog(){};

		/*! \brief Analyze user changes and performs the ALTER TABLE sql
		\retval bool true on succes, false on error
		*/
		bool alterTable();
		bool update;

	private:
		//! \brief original name of the table. It's compared with new name for renaming procedure.
		QString currentTable;
		//! \brief rowcount of the original table. User cannot remove these rows.
		int protectedRows;

		//! \brief Setup the OK button if there is something changed
		void checkChanges();

	private slots:
		void addField();
		void removeField();
		void fieldSelected();
		//! \brief Check if to allow user changes in the table column (qtable row).
		void cellClicked(int, int);

		void nameEdit_textChanged(const QString&);
		void createButton_clicked();
};

#endif
