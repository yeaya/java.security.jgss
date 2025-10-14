#include <sun/security/krb5/internal/tools/Ktab.h>

#include <java/io/BufferedReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/PrintStream.h>
#include <java/io/Reader.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/Math.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/text/DateFormat.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/Locale.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>
#include <jcpp.h>

#undef SHORT
#undef US

using $KeyTabEntryArray = $Array<::sun::security::krb5::internal::ktab::KeyTabEntry>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $BufferedReader = ::java::io::BufferedReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $DateFormat = ::java::text::DateFormat;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $Locale = ::java::util::Locale;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;
using $KeyTabEntry = ::sun::security::krb5::internal::ktab::KeyTabEntry;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

$FieldInfo _Ktab_FieldInfo_[] = {
	{"table", "Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, 0, $field(Ktab, table)},
	{"action", "C", nullptr, 0, $field(Ktab, action)},
	{"name", "Ljava/lang/String;", nullptr, 0, $field(Ktab, name)},
	{"principal", "Ljava/lang/String;", nullptr, 0, $field(Ktab, principal)},
	{"showEType", "Z", nullptr, 0, $field(Ktab, showEType)},
	{"showTime", "Z", nullptr, 0, $field(Ktab, showTime)},
	{"etype", "I", nullptr, 0, $field(Ktab, etype)},
	{"password", "[C", nullptr, 0, $field(Ktab, password)},
	{"forced", "Z", nullptr, 0, $field(Ktab, forced)},
	{"append", "Z", nullptr, 0, $field(Ktab, append)},
	{"vDel", "I", nullptr, 0, $field(Ktab, vDel)},
	{"vAdd", "I", nullptr, 0, $field(Ktab, vAdd)},
	{}
};

$MethodInfo _Ktab_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Ktab::*)()>(&Ktab::init$))},
	{"addEntry", "()V", nullptr, 0},
	{"deleteEntry", "()V", nullptr, 0},
	{"error", "([Ljava/lang/String;)V", nullptr, $TRANSIENT},
	{"listKt", "()V", nullptr, 0},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($StringArray*)>(&Ktab::main))},
	{"printHelp", "()V", nullptr, 0},
	{"processArgs", "([Ljava/lang/String;)V", nullptr, 0},
	{}
};

$ClassInfo _Ktab_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.tools.Ktab",
	"java.lang.Object",
	nullptr,
	_Ktab_FieldInfo_,
	_Ktab_MethodInfo_
};

$Object* allocate$Ktab($Class* clazz) {
	return $of($alloc(Ktab));
}

void Ktab::init$() {
	this->etype = -1;
	$set(this, password, nullptr);
	this->forced = false;
	this->append = false;
	this->vDel = -1;
	this->vAdd = -1;
}

void Ktab::main($StringArray* args) {
	$var(Ktab, ktab, $new(Ktab));
	bool var$0 = ($nc(args)->length == 1);
	if (var$0) {
		bool var$3 = ($nc(args->get(0))->equalsIgnoreCase("-?"_s));
		bool var$2 = var$3 || ($nc($nc(args)->get(0))->equalsIgnoreCase("-h"_s));
		bool var$1 = var$2 || ($nc($nc(args)->get(0))->equalsIgnoreCase("--help"_s));
		var$0 = (var$1 || ($nc(args->get(0))->equalsIgnoreCase("-help"_s)));
	}
	if (var$0) {
		ktab->printHelp();
		$System::exit(0);
		return;
	} else if ((args == nullptr) || (args->length == 0)) {
		ktab->action = u'l';
	} else {
		ktab->processArgs(args);
	}
	$set(ktab, table, $KeyTab::getInstance(ktab->name));
	if ($nc(ktab->table)->isMissing() && ktab->action != u'a') {
		if (ktab->name == nullptr) {
			$init($System);
			$nc($System::out)->println("No default key table exists."_s);
		} else {
			$init($System);
			$nc($System::out)->println($$str({"Key table "_s, ktab->name, " does not exist."_s}));
		}
		$System::exit(-1);
	}
	if (!$nc(ktab->table)->isValid()) {
		if (ktab->name == nullptr) {
			$init($System);
			$nc($System::out)->println("The format of the default key table  is incorrect."_s);
		} else {
			$init($System);
			$nc($System::out)->println($$str({"The format of key table "_s, ktab->name, " is incorrect."_s}));
		}
		$System::exit(-1);
	}
	switch (ktab->action) {
	case u'l':
		{
			ktab->listKt();
			break;
		}
	case u'a':
		{
			ktab->addEntry();
			break;
		}
	case u'd':
		{
			ktab->deleteEntry();
			break;
		}
	default:
		{
			ktab->error($$new($StringArray, {"A command must be provided"_s}));
		}
	}
}

void Ktab::processArgs($StringArray* args) {
	bool argAlreadyAppeared = false;
	for (int32_t i = 0; i < $nc(args)->length; ++i) {
		if ($nc(args->get(i))->startsWith("-"_s)) {
			{
				$init($Locale);
				$var($String, s4957$, $nc(args->get(i))->toLowerCase($Locale::US));
				int32_t tmp4957$ = -1;
				switch (s4957$->hashCode()) {
				case 1503:
					{
						if (s4957$->equals("-l"_s)) {
							tmp4957$ = 0;
						}
						break;
					}
				case 1492:
					{
						if (s4957$->equals("-a"_s)) {
							tmp4957$ = 1;
						}
						break;
					}
				case 1495:
					{
						if (s4957$->equals("-d"_s)) {
							tmp4957$ = 2;
						}
						break;
					}
				case 1496:
					{
						if (s4957$->equals("-e"_s)) {
							tmp4957$ = 3;
						}
						break;
					}
				case 1505:
					{
						if (s4957$->equals("-n"_s)) {
							tmp4957$ = 4;
						}
						break;
					}
				case 1502:
					{
						if (s4957$->equals("-k"_s)) {
							tmp4957$ = 5;
						}
						break;
					}
				case 1511:
					{
						if (s4957$->equals("-t"_s)) {
							tmp4957$ = 6;
						}
						break;
					}
				case 1497:
					{
						if (s4957$->equals("-f"_s)) {
							tmp4957$ = 7;
						}
						break;
					}
				case (int32_t)0xF85D3987:
					{
						if (s4957$->equals("-append"_s)) {
							tmp4957$ = 8;
						}
						break;
					}
				}
				switch (tmp4957$) {
				case 0:
					{
						this->action = u'l';
						break;
					}
				case 1:
					{
						this->action = u'a';
						bool var$0 = ++i >= args->length;
						if (var$0 || $nc(args->get(i))->startsWith("-"_s)) {
							error($$new($StringArray, {"A principal name must be specified after -a"_s}));
						}
						$set(this, principal, args->get(i));
						break;
					}
				case 2:
					{
						this->action = u'd';
						bool var$1 = ++i >= args->length;
						if (var$1 || $nc(args->get(i))->startsWith("-"_s)) {
							error($$new($StringArray, {"A principal name must be specified after -d"_s}));
						}
						$set(this, principal, args->get(i));
						break;
					}
				case 3:
					{
						if (this->action == u'l') {
							this->showEType = true;
						} else if (this->action == u'd') {
							bool var$2 = ++i >= args->length;
							if (var$2 || $nc(args->get(i))->startsWith("-"_s)) {
								error($$new($StringArray, {"An etype must be specified after -e"_s}));
							}
							try {
								this->etype = $Integer::parseInt(args->get(i));
								if (this->etype <= 0) {
									$throwNew($NumberFormatException);
								}
							} catch ($NumberFormatException&) {
								$var($NumberFormatException, nfe, $catch());
								error($$new($StringArray, {$$str({args->get(i), " is not a valid etype"_s})}));
							}
						} else {
							error($$new($StringArray, {$$str({args->get(i), " is not valid after -"_s, $$str(this->action)})}));
						}
						break;
					}
				case 4:
					{
						bool var$3 = ++i >= args->length;
						if (var$3 || $nc(args->get(i))->startsWith("-"_s)) {
							error($$new($StringArray, {"A KVNO must be specified after -n"_s}));
						}
						try {
							this->vAdd = $Integer::parseInt(args->get(i));
							if (this->vAdd < 0) {
								$throwNew($NumberFormatException);
							}
						} catch ($NumberFormatException&) {
							$var($NumberFormatException, nfe, $catch());
							error($$new($StringArray, {$$str({args->get(i), " is not a valid KVNO"_s})}));
						}
						break;
					}
				case 5:
					{
						bool var$4 = ++i >= args->length;
						if (var$4 || $nc(args->get(i))->startsWith("-"_s)) {
							error($$new($StringArray, {"A keytab name must be specified after -k"_s}));
						}
						bool var$5 = $nc(args->get(i))->length() >= 5;
						if (var$5 && $($nc(args->get(i))->substring(0, 5))->equalsIgnoreCase("FILE:"_s)) {
							$set(this, name, $nc(args->get(i))->substring(5));
						} else {
							$set(this, name, args->get(i));
						}
						break;
					}
				case 6:
					{
						this->showTime = true;
						break;
					}
				case 7:
					{
						this->forced = true;
						break;
					}
				case 8:
					{
						this->append = true;
						break;
					}
				default:
					{
						error($$new($StringArray, {$$str({"Unknown command: "_s, args->get(i)})}));
						break;
					}
				}
			}
		} else {
			if (argAlreadyAppeared) {
				error($$new($StringArray, {$$str({"Useless extra argument "_s, args->get(i)})}));
			}
			if (this->action == u'a') {
				$set(this, password, $nc(args->get(i))->toCharArray());
			} else if (this->action == u'd') {
				{
					$var($String, s8958$, args->get(i));
					int32_t tmp8958$ = -1;
					switch ($nc(s8958$)->hashCode()) {
					case 0x000179A1:
						{
							if (s8958$->equals("all"_s)) {
								tmp8958$ = 0;
							}
							break;
						}
					case 0x0001AE27:
						{
							if (s8958$->equals("old"_s)) {
								tmp8958$ = 1;
							}
							break;
						}
					}
					switch (tmp8958$) {
					case 0:
						{
							this->vDel = -1;
							break;
						}
					case 1:
						{
							this->vDel = -2;
							break;
						}
					default:
						{
							{
								try {
									this->vDel = $Integer::parseInt(args->get(i));
									if (this->vDel < 0) {
										$throwNew($NumberFormatException);
									}
								} catch ($NumberFormatException&) {
									$var($NumberFormatException, nfe, $catch());
									error($$new($StringArray, {$$str({args->get(i), " is not a valid KVNO"_s})}));
								}
							}
						}
					}
				}
			} else {
				error($$new($StringArray, {$$str({"Useless extra argument "_s, args->get(i)})}));
			}
			argAlreadyAppeared = true;
		}
	}
}

void Ktab::addEntry() {
	$var($PrincipalName, pname, nullptr);
	try {
		$assign(pname, $new($PrincipalName, this->principal));
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$init($System);
		$nc($System::err)->println($$str({"Failed to add "_s, this->principal, " to keytab."_s}));
		e->printStackTrace();
		$System::exit(-1);
	}
	if (this->password == nullptr) {
		try {
			$init($System);
			$var($BufferedReader, cis, $new($BufferedReader, $$new($InputStreamReader, $System::in)));
			$nc($System::out)->print($$str({"Password for "_s, $($nc(pname)->toString()), ":"_s}));
			$nc($System::out)->flush();
			$set(this, password, $nc($(cis->readLine()))->toCharArray());
		} catch ($IOException&) {
			$var($IOException, e, $catch());
			$init($System);
			$nc($System::err)->println("Failed to read the password."_s);
			e->printStackTrace();
			$System::exit(-1);
		}
	}
	try {
		$nc(this->table)->addEntry(pname, this->password, this->vAdd, this->append);
		$Arrays::fill(this->password, u'0');
		$nc(this->table)->save();
		$init($System);
		$nc($System::out)->println("Done!"_s);
		$nc($System::out)->println($$str({"Service key for "_s, this->principal, " is saved in "_s, $($nc(this->table)->tabName())}));
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$init($System);
		$nc($System::err)->println($$str({"Failed to add "_s, this->principal, " to keytab."_s}));
		e->printStackTrace();
		$System::exit(-1);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$init($System);
		$nc($System::err)->println("Failed to save new entry."_s);
		e->printStackTrace();
		$System::exit(-1);
	}
}

void Ktab::listKt() {
	$init($System);
	$nc($System::out)->println($$str({"Keytab name: "_s, $($nc(this->table)->tabName())}));
	$var($KeyTabEntryArray, entries, $nc(this->table)->getEntries());
	if ((entries != nullptr) && (entries->length > 0)) {
		$var($StringArray2, output, $new($StringArray2, entries->length + 1, this->showTime ? 3 : 2));
		int32_t column = 0;
		$nc(output->get(0))->set(column++, "KVNO"_s);
		if (this->showTime) {
			$nc(output->get(0))->set(column++, "Timestamp"_s);
		}
		$nc(output->get(0))->set(column++, "Principal"_s);
		for (int32_t i = 0; i < entries->length; ++i) {
			column = 0;
			$nc(output->get(i + 1))->set(column++, $($nc($($nc($($nc(entries->get(i))->getKey()))->getKeyVersionNumber()))->toString()));
			if (this->showTime) {
				$nc(output->get(i + 1))->set(column++, $($nc($($DateFormat::getDateTimeInstance($DateFormat::SHORT, $DateFormat::SHORT)))->format($$new($Date, $nc($($nc(entries->get(i))->getTimeStamp()))->getTime()))));
			}
			$var($String, princ, $nc($($nc(entries->get(i))->getService()))->toString());
			if (this->showEType) {
				int32_t e = $nc($($nc(entries->get(i))->getKey()))->getEType();
				$nc(output->get(i + 1))->set(column++, $$str({princ, " ("_s, $$str(e), ":"_s, $($EType::toString(e)), ")"_s}));
			} else {
				$nc(output->get(i + 1))->set(column++, princ);
			}
		}
		$var($ints, width, $new($ints, column));
		for (int32_t j = 0; j < column; ++j) {
			for (int32_t i = 0; i <= entries->length; ++i) {
				if ($nc($nc(output->get(i))->get(j))->length() > width->get(j)) {
					width->set(j, $nc($nc(output->get(i))->get(j))->length());
				}
			}
			if (j != 0) {
				width->set(j, -width->get(j));
			}
		}
		for (int32_t j = 0; j < column; ++j) {
			$nc($System::out)->printf($$str({"%"_s, $$str(width->get(j)), "s "_s}), $$new($ObjectArray, {$of($nc(output->get(0))->get(j))}));
		}
		$nc($System::out)->println();
		for (int32_t j = 0; j < column; ++j) {
			for (int32_t k = 0; k < $Math::abs(width->get(j)); ++k) {
				$nc($System::out)->print("-"_s);
			}
			$nc($System::out)->print(" "_s);
		}
		$nc($System::out)->println();
		for (int32_t i = 0; i < entries->length; ++i) {
			for (int32_t j = 0; j < column; ++j) {
				$nc($System::out)->printf($$str({"%"_s, $$str(width->get(j)), "s "_s}), $$new($ObjectArray, {$of($nc(output->get(i + 1))->get(j))}));
			}
			$nc($System::out)->println();
		}
	} else {
		$nc($System::out)->println("0 entry."_s);
	}
}

void Ktab::deleteEntry() {
	$var($PrincipalName, pname, nullptr);
	try {
		$assign(pname, $new($PrincipalName, this->principal));
		if (!this->forced) {
			$var($String, answer, nullptr);
			$init($System);
			$var($BufferedReader, cis, $new($BufferedReader, $$new($InputStreamReader, $System::in)));
			$var($String, var$1, $$str({"Are you sure you want to delete service key(s) for "_s, $(pname->toString()), " ("_s, (this->etype == -1 ? "all etypes"_s : ($$str({"etype="_s, $$str(this->etype)}))), ", "_s, (this->vDel == -1 ? "all kvno"_s : (this->vDel == -2 ? "old kvno"_s : ($$str({"kvno="_s, $$str(this->vDel)})))), ") in "_s}));
			$var($String, var$0, $$concat(var$1, $($nc(this->table)->tabName())));
			$nc($System::out)->print($$concat(var$0, "? (Y/[N]): "));
			$nc($System::out)->flush();
			$assign(answer, cis->readLine());
			bool var$2 = $nc(answer)->equalsIgnoreCase("Y"_s);
			if (var$2 || $nc(answer)->equalsIgnoreCase("Yes"_s)) {
			} else {
				$System::exit(0);
			}
		}
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$init($System);
		$nc($System::err)->println("Error occurred while deleting the entry. Deletion failed."_s);
		e->printStackTrace();
		$System::exit(-1);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$init($System);
		$nc($System::err)->println("Error occurred while deleting the entry.  Deletion failed."_s);
		e->printStackTrace();
		$System::exit(-1);
	}
	int32_t count = $nc(this->table)->deleteEntries(pname, this->etype, this->vDel);
	if (count == 0) {
		$init($System);
		$nc($System::err)->println("No matched entry in the keytab. Deletion fails."_s);
		$System::exit(-1);
	} else {
		try {
			$nc(this->table)->save();
		} catch ($IOException&) {
			$var($IOException, e, $catch());
			$init($System);
			$nc($System::err)->println("Error occurs while saving the keytab. Deletion fails."_s);
			e->printStackTrace();
			$System::exit(-1);
		}
		$init($System);
		$nc($System::out)->println($$str({"Done! "_s, $$str(count), " entries removed."_s}));
	}
}

void Ktab::error($StringArray* errors) {
	{
		$var($StringArray, arr$, errors);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, error, arr$->get(i$));
			{
				$init($System);
				$nc($System::out)->println($$str({"Error: "_s, error, "."_s}));
			}
		}
	}
	printHelp();
	$System::exit(-1);
}

void Ktab::printHelp() {
	$init($System);
	$nc($System::out)->println("\nUsage: ktab <commands> <options>"_s);
	$nc($System::out)->println();
	$nc($System::out)->println("Available commands:"_s);
	$nc($System::out)->println();
	$nc($System::out)->println("-l [-e] [-t]\n    list the keytab name and entries. -e with etype, -t with timestamp."_s);
	$nc($System::out)->println("-a <principal name> [<password>] [-n <kvno>] [-append]\n    add new key entries to the keytab for the given principal name with\n    optional <password>. If a <kvno> is specified, new keys\' Key Version\n    Numbers equal to the value, otherwise, automatically incrementing\n    the Key Version Numbers. If -append is specified, new keys are\n    appended to the keytab, otherwise, old keys for the\n    same principal are removed."_s);
	$nc($System::out)->println("-d <principal name> [-f] [-e <etype>] [<kvno> | all | old]\n    delete key entries from the keytab for the specified principal. If\n    <kvno> is specified, delete keys whose Key Version Numbers match\n    kvno. If \"all\" is specified, delete all keys. If \"old\" is specified,\n    delete all keys except those with the highest kvno. Default action\n    is \"all\". If <etype> is specified, only keys of this encryption type\n    are deleted. <etype> should be specified as the numberic value etype\n    defined in RFC 3961, section 8. A prompt to confirm the deletion is\n    displayed unless -f is specified."_s);
	$nc($System::out)->println();
	$nc($System::out)->println("Common option(s):"_s);
	$nc($System::out)->println();
	$nc($System::out)->println("-k <keytab name>\n    specify keytab name and path with prefix FILE:"_s);
}

Ktab::Ktab() {
}

$Class* Ktab::load$($String* name, bool initialize) {
	$loadClass(Ktab, name, initialize, &_Ktab_ClassInfo_, allocate$Ktab);
	return class$;
}

$Class* Ktab::class$ = nullptr;

				} // tools
			} // internal
		} // krb5
	} // security
} // sun