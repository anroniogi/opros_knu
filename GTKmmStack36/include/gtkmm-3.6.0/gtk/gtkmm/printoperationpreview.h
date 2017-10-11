// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_PRINTOPERATIONPREVIEW_H
#define _GTKMM_PRINTOPERATIONPREVIEW_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <glibmm/interface.h>

#include <gtkmm/pagesetup.h>
#include <gtkmm/printcontext.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkPrintOperationPreviewIface GtkPrintOperationPreviewIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkPrintOperationPreview GtkPrintOperationPreview;
typedef struct _GtkPrintOperationPreviewClass GtkPrintOperationPreviewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class PrintOperationPreview_Class; } // namespace Gtk
namespace Gtk
{

//TODO: There is no GtkPrintOperationPreview documentation either.
// See http://bugzilla.gnome.org/show_bug.cgi?id=575538
/**
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class PrintOperationPreview : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef PrintOperationPreview CppObjectType;
  typedef PrintOperationPreview_Class CppClassType;
  typedef GtkPrintOperationPreview BaseObjectType;
  typedef GtkPrintOperationPreviewIface BaseClassType;

private:
  friend class PrintOperationPreview_Class;
  static CppClassType printoperationpreview_class_;

  // noncopyable
  PrintOperationPreview(const PrintOperationPreview&);
  PrintOperationPreview& operator=(const PrintOperationPreview&);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  PrintOperationPreview();
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit PrintOperationPreview(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit PrintOperationPreview(GtkPrintOperationPreview* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~PrintOperationPreview();

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkPrintOperationPreview*       gobj()       { return reinterpret_cast<GtkPrintOperationPreview*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkPrintOperationPreview* gobj() const { return reinterpret_cast<GtkPrintOperationPreview*>(gobject_); }

private:

public:

  
  /** Renders a page to the preview, using the print context that
   * was passed to the Gtk::PrintOperation::signal_preview() handler together
   * with @a preview.
   * 
   * A custom iprint preview should use this function in its signal_expose()
   * handler to render the currently selected page.
   * 
   * Note that this function requires a suitable cairo context to 
   * be associated with the print context. 
   * 
   * @newin{2,10}
   * @param page_nr The page to render.
   */
  void render_page(int page_nr);
  
  /** Ends a preview. 
   * 
   * This function must be called to finish a custom print preview.
   * 
   * @newin{2,10}
   */
  void end_preview();
  
  /** Returns whether the given page is included in the set of pages that
   * have been selected for printing.
   * 
   * @newin{2,10}
   * @param page_nr A page number.
   * @return <tt>true</tt> if the page has been selected for printing.
   */
  bool is_selected(int page_nr) const;

    virtual void render_page_vfunc(int page_nr);

    virtual void end_preview_vfunc();

    virtual bool is_selected_vfunc(int page_nr) const;


/**
   * @par Slot Prototype:
   * <tt>void on_my_%ready(const Glib::RefPtr<PrintContext>& context)</tt>
   *
   * The signal_ready() signal gets emitted once per preview operation,
   * before the first page is rendered.
   * 
   * A handler for this signal can be used for setup tasks.
   * @param context The current Gtk::PrintContext.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<PrintContext>& > signal_ready();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%got_page_size(const Glib::RefPtr<PrintContext>& context, const Glib::RefPtr<PageSetup>& page_setup)</tt>
   *
   * The signal_got_page_size() signal is emitted once for each page
   * that gets rendered to the preview. 
   * 
   * A handler for this signal should update the @a context
   * according to @a page_setup and set up a suitable cairo
   * context, using Gtk::PrintContext::set_cairo_context().
   * @param context The current Gtk::PrintContext.
   * @param page_setup The Gtk::PageSetup for the current page.
   */

  Glib::SignalProxy2< void,const Glib::RefPtr<PrintContext>&,const Glib::RefPtr<PageSetup>& > signal_got_page_size();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_ready().
  virtual void on_ready(const Glib::RefPtr<PrintContext>& context);
  /// This is a default handler for the signal signal_got_page_size().
  virtual void on_got_page_size(const Glib::RefPtr<PrintContext>& context, const Glib::RefPtr<PageSetup>& page_setup);


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::PrintOperationPreview
   */
  Glib::RefPtr<Gtk::PrintOperationPreview> wrap(GtkPrintOperationPreview* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_PRINTOPERATIONPREVIEW_H */

