/* GAIL - The GNOME Accessibility Implementation Library
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_PANED_ACCESSIBLE_H__
#define __GTK_PANED_ACCESSIBLE_H__

#include "gtkcontaineraccessible.h"

G_BEGIN_DECLS

#define GTK_TYPE_PANED_ACCESSIBLE                      (_gtk_paned_accessible_get_type ())
#define GTK_PANED_ACCESSIBLE(obj)                      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_PANED_ACCESSIBLE, GtkPanedAccessible))
#define GTK_PANED_ACCESSIBLE_CLASS(klass)              (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_PANED_ACCESSIBLE, GtkPanedAccessibleClass))
#define GTK_IS_PANED_ACCESSIBLE(obj)                   (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_PANED_ACCESSIBLE))
#define GTK_IS_PANED_ACCESSIBLE_CLASS(klass)           (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_PANED_ACCESSIBLE))
#define GTK_PANED_ACCESSIBLE_GET_CLASS(obj)            (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_PANED_ACCESSIBLE, GtkPanedAccessibleClass))

typedef struct _GtkPanedAccessible        GtkPanedAccessible;
typedef struct _GtkPanedAccessibleClass   GtkPanedAccessibleClass;
typedef struct _GtkPanedAccessiblePrivate GtkPanedAccessiblePrivate;

struct _GtkPanedAccessible
{
  GtkContainerAccessible parent;

  GtkPanedAccessiblePrivate *priv;
};

struct _GtkPanedAccessibleClass
{
  GtkContainerAccessibleClass parent_class;
};

GType _gtk_paned_accessible_get_type (void);

G_END_DECLS

#endif /* __GTK_PANED_ACCESSIBLE_H__ */
