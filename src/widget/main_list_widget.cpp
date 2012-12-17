/*
 * main_list_widget.cpp
 *
 *  Created on: 2011-8-19
 *      Author: Young <public0821@gmail.com>
 */

#include "main_list_widget.h"
#include <qicon.h>
#include <qmessagebox.h>
#include "npg_define.h"
#include "protocol/protocol_factory.h"

MainListWidget::MainListWidget(const QMap<QString, QString>& name_icons, QWidget* parent)
:QListWidget(parent)
{
	setIconSize( QSize(64, 64));
//	setViewMode(QListView::IconMode);
//	setFlow(QListView::TopToBottom);
	QMap<QString, QString>::const_iterator it_name_icon;
	for (it_name_icon = name_icons.begin(); it_name_icon != name_icons.end(); ++it_name_icon)
	{
		QListWidgetItem* item = new QListWidgetItem(
			QIcon(it_name_icon.value()), it_name_icon.key(),
			this);
		item->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
	}
	ProtocolFactory& protocol_factory = ProtocolFactory::instance();
	bool ret = protocol_factory.loadXml();
	if (!ret)
	{
		QMessageBox::information(this, tr("tip"), tr("load config failed"));
	}	
	const std::vector<Protocol>& protocols = protocol_factory.protocols();
	std::vector<Protocol>::const_iterator it_protocol;
	for (it_protocol = protocols.begin(); it_protocol != protocols.end(); ++it_protocol)
	{
		QListWidgetItem* item = new QListWidgetItem(
			QIcon(it_protocol->icon()), it_protocol->name(),
			this);
		item->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
	}
	
}

MainListWidget::~MainListWidget()
{
}

