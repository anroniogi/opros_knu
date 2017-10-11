// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_FILEOUTPUTSTREAM_H
#define _GIOMM_FILEOUTPUTSTREAM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <giomm/outputstream.h>
#include <giomm/seekable.h>
#include <giomm/fileinfo.h>
#include <glibmm/object.h>
#include <glibmm/iochannel.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GFileOutputStream GFileOutputStream;
typedef struct _GFileOutputStreamClass GFileOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{ class FileOutputStream_Class; } // namespace Gio
namespace Gio
{


/** FileOutputStream provides output streams that write their content to a file.
 *
 * FileOutputStream implements Seekable, which allows the output stream to jump
 * to arbitrary positions in the file and to truncate the file, provided the
 * file system of the file supports these operations.
 * Use the methods of the Seekable base class for seeking and positioning.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class FileOutputStream
: public OutputStream,
  public Seekable
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef FileOutputStream CppObjectType;
  typedef FileOutputStream_Class CppClassType;
  typedef GFileOutputStream BaseObjectType;
  typedef GFileOutputStreamClass BaseClassType;

private:  friend class FileOutputStream_Class;
  static CppClassType fileoutputstream_class_;

private:
  // noncopyable
  FileOutputStream(const FileOutputStream&);
  FileOutputStream& operator=(const FileOutputStream&);

protected:
  explicit FileOutputStream(const Glib::ConstructParams& construct_params);
  explicit FileOutputStream(GFileOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~FileOutputStream();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GFileOutputStream*       gobj()       { return reinterpret_cast<GFileOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GFileOutputStream* gobj() const { return reinterpret_cast<GFileOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GFileOutputStream* gobj_copy();

private:

  
public:

  /** Queries a file output stream for the given @a attributes .
   * This function blocks while querying the stream. For the asynchronous
   * version of this function, see query_info_async().
   * While the stream is blocked, the stream will set the pending flag
   * internally, and any other operations on the stream will throw a Gio::Error with
   * PENDING.
   *
   * Can fail if the stream was already closed (with a
   * CLOSED error), the stream has pending operations (with a PENDING error),
   * or if querying info is not supported for
   * the stream's interface (with a NOT_SUPPORTED error). In
   * all cases of failure, an empty RefPtr will be returned.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown, and an empty RefPtr will
   * be returned.
   *
   * @param cancellable A Cancellable object.
   * @param attributes A file attribute query string.
   * @return A FileInfo for the stream, or an empty RefPtr on error.
   */
  Glib::RefPtr<FileInfo> query_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*");

  /** Queries a file output stream for the given @a attributes .
   * This function blocks while querying the stream. For the asynchronous
   * version of this function, see query_info_async().
   * While the stream is blocked, the stream will set the pending flag
   * internally, and any other operations on the stream will throw a Gio::Error with
   * PENDING.
   *
   * Can fail if the stream was already closed (with a CLOSED error),
   * the stream has pending operations (with an PENDING error),
   * or if querying info is not supported for
   * the stream's interface (with a NOT_SUPPORTED error). In
   * all cases of failure, an empty RefPtr will be returned.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown, and an empty RefPtr will
   * be returned.
   *
   * @param cancellable A Cancellable object.
   * @param attributes A file attribute query string.
   * @return A FileInfo for the stream, or an empty RefPtr on error.
   */
  Glib::RefPtr<FileInfo> query_info(const std::string& attributes = "*");
  

  /** Queries the stream information asynchronously.
   * When the operation is finished @a slot will be called.
   * You can then call query_info_finish()
   * to get the result of the operation.
   *
   * For the synchronous version of this function,
   * see query_info().
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown
   *
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param attributes A file attribute query string.
   * @param io_priority The <io-priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);

  /** Queries the stream information asynchronously.
   * When the operation is finished @a slot will be called.
   * You can then call query_info_finish()
   * to get the result of the operation.
   *
   * For the synchronous version of this function,
   * see query_info().
   *
   * @param slot Callback to call when the request is satisfied.
   * @param attributes A file attribute query string.
   * @param io_priority The <io-priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);
  

  /** Finalizes the asynchronous query started 
   * by g_file_output_stream_query_info_async().
   * @param result A AsyncResult.
   * @return A FileInfo for the finished query.
   */
  Glib::RefPtr<FileInfo> query_info_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Gets the entity tag for the file when it has been written.
   * This must be called after the stream has been written
   * and closed, as the etag can change while writing.
   * @return The entity tag for the stream.
   */
  std::string get_etag() const;

  //These seem to be just C convenience functions - they are already in the Seekable base class:
  //See http://bugzilla.gnome.org/show_bug.cgi?id=509990
  
//  _WRAP_METHOD(goffset tell() const, g_file_output_stream_tell)
//  _WRAP_METHOD(bool can_seek() const, g_file_output_stream_can_seek)
//  _WRAP_METHOD(bool seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable),
//               g_file_output_stream_seek,
//               errthrow)
//  _WRAP_METHOD(bool can_truncate() const, g_file_output_stream_can_truncate)
//  _WRAP_METHOD(bool truncate(goffset size, const Glib::RefPtr<Cancellable>& cancellable),
//               g_file_output_stream_truncate,
//               errthrow)


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
   * @relates Gio::FileOutputStream
   */
  Glib::RefPtr<Gio::FileOutputStream> wrap(GFileOutputStream* object, bool take_copy = false);
}


#endif /* _GIOMM_FILEOUTPUTSTREAM_H */

