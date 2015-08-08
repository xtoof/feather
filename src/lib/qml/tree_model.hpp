/***********************************************************************
 *
 * Filename: tree_model.hpp
 *
 * Description: qml list model used by the outliner.
 *
 * Copyright (C) 2015 Richard Layman, rlayman2000@yahoo.com 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/
#ifndef TREE_MODEL_HPP
#define TREE_MODEL_HPP

#include "deps.hpp"
#include "qml_deps.hpp"
#include "field.hpp"
#include "commands.hpp"

class Leaf
{
    public:
        explicit Leaf(const QList<QVariant> &data, Leaf *parentItem = 0);
        ~Leaf();

        void appendChild(Leaf *child);

        Leaf *child(int row);
        int childCount() const;
        int columnCount() const;
        QVariant data(int column) const;
        int row() const;
        Leaf *parentItem();

    private:
        QList<Leaf*> m_childItems;
        QList<QVariant> m_itemData;
        Leaf *m_parentItem;
        int uid;
        int nid;
};


// TREE MODEL

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

    public:
        explicit TreeModel(QObject *parent = 0);
        ~TreeModel();

        enum ERoles
        {
            UidRole = Qt::UserRole + 1,
            NidRole
        };


        QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
        Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
        QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
        int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
        Q_INVOKABLE void updateTree();

    protected:
        QHash<int,QByteArray> roleNames() const;


    private:
        void setupModelData(Leaf *parent);

        Leaf *rootItem;
};


#endif
