// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GLIBMM_KEYFILE_H
#define _GLIBMM_KEYFILE_H


/* Copyright(C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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


#include <glibmmconfig.h>
#include <glibmm/ustring.h>
#include <glibmm/arrayhandle.h>
#include <glibmm/error.h>
#include <glibmm/utility.h>
#include <glib.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GKeyFile GKeyFile; }
#endif

namespace Glib
{

  /** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%KeyFileFlags operator|(KeyFileFlags, KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags operator&(KeyFileFlags, KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags operator^(KeyFileFlags, KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags operator~(KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags& operator|=(KeyFileFlags&, KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags& operator&=(KeyFileFlags&, KeyFileFlags)</tt><br>
 * <tt>%KeyFileFlags& operator^=(KeyFileFlags&, KeyFileFlags)</tt><br>
 */
enum KeyFileFlags
{
  KEY_FILE_NONE = 0x0,
  KEY_FILE_KEEP_COMMENTS = 1 << 0,
  KEY_FILE_KEEP_TRANSLATIONS = 1 << 1
};

/** @ingroup glibmmEnums */
inline KeyFileFlags operator|(KeyFileFlags lhs, KeyFileFlags rhs)
  { return static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline KeyFileFlags operator&(KeyFileFlags lhs, KeyFileFlags rhs)
  { return static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline KeyFileFlags operator^(KeyFileFlags lhs, KeyFileFlags rhs)
  { return static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline KeyFileFlags operator~(KeyFileFlags flags)
  { return static_cast<KeyFileFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline KeyFileFlags& operator|=(KeyFileFlags& lhs, KeyFileFlags rhs)
  { return (lhs = static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline KeyFileFlags& operator&=(KeyFileFlags& lhs, KeyFileFlags rhs)
  { return (lhs = static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline KeyFileFlags& operator^=(KeyFileFlags& lhs, KeyFileFlags rhs)
  { return (lhs = static_cast<KeyFileFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** Exception class for KeyFile errors.
 */
class KeyFileError : public Glib::Error
{
public:
  enum Code
  {
    UNKNOWN_ENCODING,
    PARSE,
    NOT_FOUND,
    KEY_NOT_FOUND,
    GROUP_NOT_FOUND,
    INVALID_VALUE
  };

  KeyFileError(Code error_code, const Glib::ustring& error_message);
  explicit KeyFileError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** This class lets you parse, edit or create files containing groups of key-value pairs, which we call key files
 * for lack of a better name. Several freedesktop.org specifications use key files now, e.g the Desktop Entry
 * Specification and the Icon Theme Specification.
 *
 * The syntax of key files is described in detail in the Desktop Entry Specification, here is a quick summary: Key
 * files consists of groups of key-value pairs, interspersed with comments.
 *
 * @code
 * # this is just an example
 * # there can be comments before the first group
 *
 * [First Group]
 *
 * Name=Key File Example\tthis value shows\nescaping
 *
 * # localized strings are stored in multiple key-value pairs
 * Welcome=Hello
 * Welcome[de]=Hallo
 * Welcome[fr]=Bonjour
 * Welcome[it]=Ciao
 *
 * [Another Group]
 *
 * Numbers=2;20;-200;0
 *
 * Booleans=true;false;true;true
 * @endcode
 *
 * Lines beginning with a '#' and blank lines are considered comments.
 *
 * Groups are started by a header line containing the group name enclosed in '[' and ']', and ended implicitly by
 * the start of the next group or the end of the file. Each key-value pair must be contained in a group.
 *
 * Key-value pairs generally have the form key=value, with the exception of localized strings, which have the form
 * key[locale]=value. Space before and after the '=' character are ignored. Newline, tab, carriage return and
 * backslash characters in value are escaped as \\n, \\t, \\r, and \\\\, respectively. To preserve leading spaces in
 * values, these can also be escaped as \\s.
 *
 * Key files can store strings (possibly with localized variants), integers, booleans and lists of these. Lists are
 * separated by a separator character, typically ';' or ','. To use the list separator character in a value in a
 * list, it has to be escaped by prefixing it with a backslash.
 *
 * This syntax is obviously inspired by the .ini files commonly met on Windows, but there are some important
 * differences:
 * - .ini files use the ';' character to begin comments, key files use the '#' character.
 * - Key files allow only comments before the first group.
 * - Key files are always encoded in UTF-8.
 * - Key and Group names are case-sensitive, for example a group called [GROUP] is a different group from [group].
 *
 * Note that in contrast to the Desktop Entry Specification, groups in key files may contain the same key multiple
 * times; the last entry wins. Key files may also contain multiple groups with the same name; they are merged
 * together. Another difference is that keys and group names in key files are not restricted to ASCII characters.
 *
 * @newin{2,14}
 */
class KeyFile
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef KeyFile CppObjectType;
  typedef GKeyFile BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:

  //TODO: GKeyFile now seems to be a reference-counted type.

  //TODO: Maybe replace all the get_*/set_* methods with some generic get/set
  //methods when it is possible.

  /** Creates a new, empty KeyFile object.
   */
  KeyFile();

  /** Destructor
   */
  ~KeyFile();
  

  /** Creates a glibmm KeyFile wrapper for a GKeyFile object.
   * Note, when using this that when the wrapper is deleted,
   * it will not automatically deleted the GKeyFile unless you
   * set the delete_c_instance boolean to true.
   * @param castitem The C instance to wrap
   * @param delete_c_instance If the C instance should be deleted when
   * the wrapper is deleted.
   */
  KeyFile(GKeyFile* castitem, bool takes_ownership = false);

public:
  
  /** Loads a key file into an empty KeyFile instance.
   * If the file could not be loaded then a FileError or KeyFileError exception is thrown.
   * 
   * \throw Glib::FileError
   * \throw Glib::KeyFileError
   * @param file The path of a filename to load, in the GLib file name encoding.
   * @param flags Flags from KeyFileFlags.
   * @return <tt>true</tt> if a key file could be loaded, <tt>false</tt> othewise
   * @newin{2,6}.
   */
  bool load_from_file(const std::string& filename, KeyFileFlags flags =  Glib::KEY_FILE_NONE);

  /** Loads a KeyFile from memory
   * @param data The data to use as a KeyFile
   * @param flags Bitwise combination of the flags to use for the KeyFile
   * @return true if the KeyFile was successfully loaded, false otherwise
   * @throw Glib::KeyFileError
   */
  bool load_from_data(const Glib::ustring& data, KeyFileFlags flags = Glib::KEY_FILE_NONE);
  

#ifndef GLIBMM_DISABLE_DEPRECATED


  /** This function looks for a key file named @a file in the paths
   * specified in @a search_dirs, loads the file into @a key_file and
   * returns the file's full path in @a full_path.  If the file could not
   * be loaded then an %error is set to either a FileError or
   * KeyFileError.
   * 
   * @newin{2,14}
   * @param file A relative path to a filename to open and parse.
   * @param search_dirs <tt>0</tt>-terminated array of directories to search.
   * @param full_path Return location for a string containing the full path
   * of the file, or <tt>0</tt>.
   * @param flags Flags from KeyFileFlags.
   * @return <tt>true</tt> if a key file could be loaded, <tt>false</tt> otherwise.
   */
  bool load_from_dirs(const std::string& file, const Glib::ArrayHandle<std::string>& search_dirs, Glib::ArrayHandle<std::string>& full_path, KeyFileFlags flags =  Glib::KEY_FILE_NONE);

#endif // GLIBMM_DISABLE_DEPRECATED


  /** This function looks for a key file named @a file in the paths
   * specified in @a search_dirs, loads the file into @a key_file and
   * returns the file's full path in @a full_path.  If the file could not
   * be loaded then an %error is set to either a FileError or
   * KeyFileError.
   * 
   * @newin{2,14}
   * @param file A relative path to a filename to open and parse.
   * @param search_dirs <tt>0</tt>-terminated array of directories to search.
   * @param full_path Return location for a string containing the full path
   * of the file, or <tt>0</tt>.
   * @param flags Flags from KeyFileFlags.
   * @return <tt>true</tt> if a key file could be loaded, <tt>false</tt> otherwise.
   */

  bool load_from_dirs(const std::string& file, const Glib::ArrayHandle<std::string>& search_dirs, std::string& full_path, KeyFileFlags flags = Glib::KEY_FILE_NONE);

  /** Looks for a KeyFile named @a file in the paths returned from
   * g_get_user_data_dir() and g_get_system_data_dirs() and loads them
   * into the keyfile object, placing the full path to the file in
   * @a full_path.
   * @param file The file to search for
   * @param full_path Return location for a string containing the full path of the file
   * @param flags Bitwise combination of the flags to use for the KeyFile
   * @return true if the KeyFile was successfully loaded, false otherwise
   * @throw Glib::KeyFileError
   * @throw Glib::FileError
   */
  bool load_from_data_dirs(const std::string& file, std::string& full_path, KeyFileFlags flags = Glib::KEY_FILE_NONE);
  

  /** Outputs the KeyFile as a string
   * @return A string object holding the contents of KeyFile
   * @throw Glib::KeyFileError
   */
  Glib::ustring to_data();
  

  /** Returns the name of the start group of the file. 
   * 
   * @newin{2,6}
   * @return The start group of the key file.
   */
  Glib::ustring get_start_group() const;
	
  /** Gets a list of all groups in the KeyFile
   * @returns A list containing the names of the groups
   */
  Glib::ArrayHandle<Glib::ustring> get_groups() const;
  

  /** Gets a list of all keys from the group @a group_name.
   * @param group_name The name of a group
   * @returns A list containing the names of the keys in @a group_name
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<Glib::ustring> get_keys(const Glib::ustring& group_name) const;
  

  /** Looks whether the key file has the group @a group_name.
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @return <tt>true</tt> if @a group_name is a part of @a key_file, <tt>false</tt>
   * otherwise.
   */
  bool has_group(const Glib::ustring& group_name) const;
  
  /** Looks whether the key file has the key @a key in the group
   *  @a group_name. 
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key name.
   * @return <tt>true</tt> if @a key is a part of @a group_name, <tt>false</tt>
   * otherwise.
   * 
   * @newin{2,6}.
   */
  bool has_key(const Glib::ustring& group_name, const Glib::ustring& key) const;
	
  
  /** Return value: a newly allocated string or <tt>0</tt>.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return A newly allocated string or <tt>0</tt> if the specified 
   * key cannot be found.
   * 
   * @newin{2,6}.
   */
  Glib::ustring get_value(const Glib::ustring& group_name, const Glib::ustring& key) const;
  
  /** Return value: a newly allocated string or <tt>0</tt>.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return A newly allocated string or <tt>0</tt> if the specified 
   * key cannot be found.
   * 
   * @newin{2,6}.
   */
  Glib::ustring get_string(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Gets the value associated with @a key under @a group_name translated
   * into the current locale.
   * @return the value as a Glib::ustring
   * @throw Glib::KeyFileError
  */
  Glib::ustring get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key) const;
  

  /** Return value: a newly allocated string or <tt>0</tt>.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @param locale A locale identifier or <tt>0</tt>.
   * @return A newly allocated string or <tt>0</tt> if the specified 
   * key cannot be found.
   * 
   * @newin{2,6}.
   */
  Glib::ustring get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale) const;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a boolean.
   * @param key The name of the key.
   * @return The value of @a key as a boolean.
   * @throw Glib::KeyFileError.
   * @newin{2,6}
   */
  bool get_boolean(const Glib::ustring& key) const;

  
  /** Return value: the value associated with the key as a boolean.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as a boolean, 
   * or <tt>false</tt> if the key was not found or could not be parsed.
   * 
   * @newin{2,6}.
   */
  bool get_boolean(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Gets the value in the first group, under @a key, interpreting it as
   * an integer.
   * @param key The name of the key
   * @return The value of @a key as an integer
   * @throw Glib::KeyFileError
   * @newin{2,6}
   */
  int get_integer(const Glib::ustring& key) const;

  
  /** Return value: the value associated with the key as an integer.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as an integer, or
   * 0 if the key was not found or could not be parsed.
   * 
   * @newin{2,6}.
   */
  int get_integer(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a signed 64-bit integer. This is similar to get_integer() but can return
   * 64-bit results without truncation.
   * @param key The name of the key.
   * @return The value of @a key as a signed 64-bit integer, or <tt>0</tt> if
   * the key was not found or could not be parsed.
   * @throw Glib::KeyFileError.
   * @newin{2,28}
   */
  gint64 get_int64(const Glib::ustring& key) const;

  
  /** Returns the value associated with @a key under @a group_name as a signed
   * 64-bit integer. This is similar to g_key_file_get_integer() but can return
   * 64-bit results without truncation.
   * 
   * @newin{2,26}
   * @param group_name A non-<tt>0</tt> group name.
   * @param key A non-<tt>0</tt> key.
   * @return The value associated with the key as a signed 64-bit integer, or
   * 0 if the key was not found or could not be parsed.
   */
  gint64 get_int64(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Gets the value in the first group, under @a key, interpreting it as
   * an unsigned 64-bit integer. This is similar to get_integer() but can
   * return large positive results without truncation.
   * @param key The name of the key.
   * @return The value of @a key as an unsigned 64-bit integer, or <tt>0</tt>
   * if the key was not found or could not be parsed.
   * @throw Glib::KeyFileError.
   * @newin{2,28}
   */
  guint64 get_uint64(const Glib::ustring& key) const;

  
  /** Returns the value associated with @a key under @a group_name as an unsigned
   * 64-bit integer. This is similar to g_key_file_get_integer() but can return
   * large positive results without truncation.
   * 
   * @newin{2,26}
   * @param group_name A non-<tt>0</tt> group name.
   * @param key A non-<tt>0</tt> key.
   * @return The value associated with the key as an unsigned 64-bit integer,
   * or 0 if the key was not found or could not be parsed.
   */
  guint64 get_uint64(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a double.
   * @param key The name of the key
   * @return The value of @a key as an double
   * @throw Glib::KeyFileError
   *
   * @newin{2,14}
   */
  double get_double(const Glib::ustring& key) const;

  
  /** Return value: the value associated with the key as a double.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as a double, or
   * 0.0 if the key was not found or could not be parsed.
   * 
   * @newin{2,14}.
   */
  double get_double(const Glib::ustring& group_name, const Glib::ustring& key) const;

  
  /** Associates a new double value with @a key under @a group_name.
   * If @a key cannot be found then it is created. 
   * 
   * @newin{2,14}
   * @param group_name A group name.
   * @param key A key.
   * @param value An double value.
   */
  void set_double(const Glib::ustring& group_name, const Glib::ustring& key, double value);

  /** Associates a new double value with @a key under the start group.
   * If @a key  cannot be found then it is created.
   *
   * @newin{2,12}
   * @param key A key.
   * @param value An double value.
   */
  void set_double(const Glib::ustring& key, double value);

  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<Glib::ustring> get_string_list(const Glib::ustring& group_name, const Glib::ustring& key) const;
  
	
  /** Returns the values associated with @a key under @a group_name
   * translated into the current locale, if available.
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<Glib::ustring> get_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key) const;

  /** Returns the values associated with @a key under @a group_name
   * translated into @a locale, if available.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param locale The name of a locale
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<Glib::ustring> get_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale) const;
  

  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of booleans
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<bool> get_boolean_list(const Glib::ustring& group_name, const Glib::ustring& key) const;
  

  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of integers
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<int> get_integer_list(const Glib::ustring& group_name, const Glib::ustring& key) const;
  

  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of doubles
   * @throw Glib::KeyFileError
   */
  Glib::ArrayHandle<double> get_double_list(const Glib::ustring& group_name, const Glib::ustring& key) const;
  

  /** Get comment from top of file
   * @return The comment
   * @throw Glib::KeyFileError
   */
  Glib::ustring get_comment() const;

  /** Get comment from above a group
   * @param group_name The group
   * @return The comment
   * @throw Glib::KeyFileError
   */
  Glib::ustring get_comment(const Glib::ustring& group_name) const;

  
  /** Retrieves a comment above @a key from @a group_name.
   * If @a key is <tt>0</tt> then @a comment will be read from above 
   *  @a group_name. If both @a key and @a group_name are <tt>0</tt>, then 
   *  @a comment will be read from above the first group in the file.
   * Use the overrides for a <tt>0</tt> @a key or @a group.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key.
   * @return The comment
   * 
   * @newin{2,6}.
   */
  Glib::ustring get_comment(const Glib::ustring& group_name, const Glib::ustring& key) const;
	
  
  /** Sets the character which is used to separate
   * values in lists. Typically ';' or ',' are used
   * as separators. The default list separator is ';'.
   * 
   * @newin{2,6}
   * @param separator The separator.
   */
  void set_list_separator(gchar separator);
  
  /** Associates a new value with @a key under @a group_name.  
   * 
   * If @a key cannot be found then it is created. If @a group_name cannot 
   * be found then it is created. To set an UTF-8 string which may contain 
   * characters that need escaping (such as newlines or spaces), use 
   * g_key_file_set_string().
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @param key A key.
   * @param value A string.
   */
  void set_value(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& value);
  
  /** Associates a new string value with @a key under @a group_name.  
   * If @a key cannot be found then it is created.  
   * If @a group_name cannot be found then it is created.
   * Unlike g_key_file_set_value(), this function handles characters
   * that need escaping, such as newlines.
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @param key A key.
   * @param string A string.
   */
  void set_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& string);
  
  /** Associates a string value for @a key and @a locale under @a group_name.
   * If the translation for @a key cannot be found then it is created.
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @param key A key.
   * @param locale A locale identifier.
   * @param string A string.
   */
  void set_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale, const Glib::ustring& string);
  
  /** Associates a new boolean value with @a key under @a group_name.
   * If @a key cannot be found then it is created. 
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @param key A key.
   * @param value <tt>true</tt> or <tt>false</tt>.
   */
  void set_boolean(const Glib::ustring& group_name, const Glib::ustring& key, bool value);
  
  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   * 
   * @newin{2,6}
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_integer(const Glib::ustring& group_name, const Glib::ustring& key, int value);
  
  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   * 
   * @newin{2,26}
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_int64(const Glib::ustring& group_name, const Glib::ustring& key, gint64 value);
  
  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   * 
   * @newin{2,26}
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_uint64(const Glib::ustring& group_name, const Glib::ustring& key, guint64 value);
	
  /** Sets a list of string values for @a key under @a group_name. If
   * key cannot be found it is created. If @a group_name cannot be found
   * it is created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding objects of type Glib::ustring
   */
  void set_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<Glib::ustring>& list);
  

  /** Sets a list of string values for the @a key under @a group_name and marks
   * them as being for @a locale. If the @a key or @a group_name cannot be
   * found, they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param locale A locale
   * @param list A list holding objects of type Glib::ustring
   */
  void set_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale, const Glib::ArrayHandle<Glib::ustring>& list);
  

  /** Sets a list of booleans for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type bool
   */
  void set_boolean_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<bool>& list);
  
	
  /** Sets a list of integers for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type int
   */
  void set_integer_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<int>& list);
  

  /** Sets a list of doubles for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type int
   *
   * @newin{2,14}
   */
  void set_double_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<double>& list);
  

  /** Places @a comment at the start of the file, before the first group.
   * @param comment The Comment
   * @throw Glib::KeyFileError
   */
  void set_comment(const Glib::ustring& comment);

  /** Places @a comment above @a group_name.
   * @param group_name The Group the comment should be above
   * @param comment The comment
   * @throw Glib::KeyFileError
   */
  void set_comment(const Glib::ustring& group_name, const Glib::ustring& comment);

  
  /** Places a comment above @a key from @a group_name.
   * If @a key is <tt>0</tt> then @a comment will be written above @a group_name.  
   * If both @a key and @a group_name  are <tt>0</tt>, then @a comment will be 
   * written above the first group in the file.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name, or <tt>0</tt>.
   * @param key A key.
   * @param comment A comment.
   */
  void set_comment(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& comment);

  
  /** Removes a comment above @a key from @a group_name.
   * If @a key is <tt>0</tt> then @a comment will be removed above @a group_name. 
   * If both @a key and @a group_name are <tt>0</tt>, then @a comment will
   * be removed above the first group in the file.
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name, or <tt>0</tt>.
   * @param key A key.
   */
  void remove_comment(const Glib::ustring& group_name, const Glib::ustring& key);
  
  /** Removes @a key in @a group_name from the key file. 
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   * @param key A key name to remove.
   */
  void remove_key(const Glib::ustring& group_name, const Glib::ustring& key);
  
  /** Removes the specified group, @a group_name, 
   * from the key file. 
   * 
   * \throw Glib::KeyFileError
   * @param group_name A group name.
   */
  void remove_group(const Glib::ustring& group_name);

  GKeyFile*       gobj()       { return gobject_; }
  const GKeyFile* gobj() const { return gobject_; }

protected:
  GKeyFile* gobject_;
  bool owns_gobject_;

private:
  // noncopyable
  KeyFile(const KeyFile&);
  KeyFile& operator=(const KeyFile&);


};

} // namespace Glib


#endif /* _GLIBMM_KEYFILE_H */

