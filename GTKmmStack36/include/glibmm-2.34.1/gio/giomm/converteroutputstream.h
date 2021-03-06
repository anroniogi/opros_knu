// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_CONVERTEROUTPUTSTREAM_H
#define _GIOMM_CONVERTEROUTPUTSTREAM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <giomm/filteroutputstream.h>
#include <giomm/pollableoutputstream.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GConverterOutputStream GConverterOutputStream;
typedef struct _GConverterOutputStreamClass GConverterOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{ class ConverterOutputStream_Class; } // namespace Gio
namespace Gio
{

class Converter;
class OutputStream;

/** ConverterOutputstream - Converter Output Stream.
 * Converter output stream implements OutputStream and allows conversion of
 * data of various types during reading.  ConverterOutputStream also implements
 * the PollableOutputStream interface.
 * @newin{2,34}
 */

class ConverterOutputStream : public FilterOutputStream,
                              public PollableOutputStream
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef ConverterOutputStream CppObjectType;
  typedef ConverterOutputStream_Class CppClassType;
  typedef GConverterOutputStream BaseObjectType;
  typedef GConverterOutputStreamClass BaseClassType;

private:  friend class ConverterOutputStream_Class;
  static CppClassType converteroutputstream_class_;

private:
  // noncopyable
  ConverterOutputStream(const ConverterOutputStream&);
  ConverterOutputStream& operator=(const ConverterOutputStream&);

protected:
  explicit ConverterOutputStream(const Glib::ConstructParams& construct_params);
  explicit ConverterOutputStream(GConverterOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~ConverterOutputStream();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GConverterOutputStream*       gobj()       { return reinterpret_cast<GConverterOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GConverterOutputStream* gobj() const { return reinterpret_cast<GConverterOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GConverterOutputStream* gobj_copy();

private:

  
protected:
    explicit ConverterOutputStream(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter);


public:
  
  /** Creates a new converter output stream for the @a base_stream.
   * @param base_stream A OutputStream.
   * @param converter A Converter.
   * @return A new OutputStream.
   */

  
  static Glib::RefPtr<ConverterOutputStream> create(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter);


  // The C function returns an unreffed private member.
  
  /** Gets the Converter that is used by @a converter_stream.
   * 
   * @newin{2,24}
   * @return The converter of the converter output stream.
   */
  Glib::RefPtr<Converter> get_converter();
  
  /** Gets the Converter that is used by @a converter_stream.
   * 
   * @newin{2,24}
   * @return The converter of the converter output stream.
   */
  Glib::RefPtr<const Converter> get_converter() const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The converter object.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Converter> > property_converter() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::ConverterOutputStream
   */
  Glib::RefPtr<Gio::ConverterOutputStream> wrap(GConverterOutputStream* object, bool take_copy = false);
}


#endif /* _GIOMM_CONVERTEROUTPUTSTREAM_H */

