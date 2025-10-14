#include <sun/security/jgss/krb5/SubjectComber.h>

#include <java/io/PrintStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/kerberos/KerberosKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>
#include <sun/security/krb5/KerberosSecrets.h>
#include <jcpp.h>

#undef DEBUG

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;
using $Subject = ::javax::security::auth::Subject;
using $KerberosKey = ::javax::security::auth::kerberos::KerberosKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $JavaxSecurityAuthKerberosAccess = ::sun::security::krb5::JavaxSecurityAuthKerberosAccess;
using $KerberosSecrets = ::sun::security::krb5::KerberosSecrets;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _SubjectComber_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SubjectComber, DEBUG)},
	{}
};

$MethodInfo _SubjectComber_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(SubjectComber::*)()>(&SubjectComber::init$))},
	{"find", "(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<TT;>;)TT;", $STATIC, $method(static_cast<$Object*(*)($Subject*,$String*,$String*,$Class*)>(&SubjectComber::find))},
	{"findAux", "(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;Z)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<TT;>;Z)Ljava/lang/Object;", $PRIVATE | $STATIC, $method(static_cast<$Object*(*)($Subject*,$String*,$String*,$Class*,bool)>(&SubjectComber::findAux))},
	{"findMany", "(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljavax/security/auth/Subject;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<TT;>;)Ljava/util/List<TT;>;", $STATIC, $method(static_cast<$List*(*)($Subject*,$String*,$String*,$Class*)>(&SubjectComber::findMany))},
	{}
};

$ClassInfo _SubjectComber_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.SubjectComber",
	"java.lang.Object",
	nullptr,
	_SubjectComber_FieldInfo_,
	_SubjectComber_MethodInfo_
};

$Object* allocate$SubjectComber($Class* clazz) {
	return $of($alloc(SubjectComber));
}

bool SubjectComber::DEBUG = false;

void SubjectComber::init$() {
}

$Object* SubjectComber::find($Subject* subject, $String* serverPrincipal, $String* clientPrincipal, $Class* credClass) {
	$init(SubjectComber);
	return $of($nc(credClass)->cast($(findAux(subject, serverPrincipal, clientPrincipal, credClass, true))));
}

$List* SubjectComber::findMany($Subject* subject, $String* serverPrincipal, $String* clientPrincipal, $Class* credClass) {
	$init(SubjectComber);
	return $cast($List, findAux(subject, serverPrincipal, clientPrincipal, credClass, false));
}

$Object* SubjectComber::findAux($Subject* subject, $String* serverPrincipal$renamed, $String* clientPrincipal$renamed, $Class* credClass, bool oneOnly) {
	$init(SubjectComber);
	$var($String, serverPrincipal, serverPrincipal$renamed);
	$var($String, clientPrincipal, clientPrincipal$renamed);
	if (subject == nullptr) {
		return $of(nullptr);
	} else {
		$var($List, answer, oneOnly ? ($List*)nullptr : static_cast<$List*>($new($ArrayList)));
		$load($KeyTab);
		if (credClass == $KeyTab::class$) {
			$var($Iterator, iterator, $nc($($nc(subject)->getPrivateCredentials($KeyTab::class$)))->iterator());
			while ($nc(iterator)->hasNext()) {
				$var($KeyTab, t, $cast($KeyTab, iterator->next()));
				if (serverPrincipal != nullptr && $nc(t)->isBound()) {
					$var($KerberosPrincipal, name, t->getPrincipal());
					if (name != nullptr) {
						if (!serverPrincipal->equals($(name->getName()))) {
							continue;
						}
					} else {
						bool found = false;
						{
							$load($KerberosPrincipal);
							$var($Iterator, i$, $nc($(subject->getPrincipals($KerberosPrincipal::class$)))->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($KerberosPrincipal, princ, $cast($KerberosPrincipal, i$->next()));
								{
									if ($nc($($nc(princ)->getName()))->equals(serverPrincipal)) {
										found = true;
										break;
									}
								}
							}
						}
						if (!found) {
							continue;
						}
					}
				}
				if (SubjectComber::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({"Found "_s, $(credClass->getSimpleName()), " "_s, t}));
				}
				if (oneOnly) {
					return $of(t);
				} else {
					$nc(answer)->add($(credClass->cast(t)));
				}
			}
		} else {
			$load($KerberosKey);
			if (credClass == $KerberosKey::class$) {
				$var($Iterator, iterator, $nc($($nc(subject)->getPrivateCredentials($KerberosKey::class$)))->iterator());
				while ($nc(iterator)->hasNext()) {
					$var($KerberosKey, t, $cast($KerberosKey, iterator->next()));
					$var($String, name, $nc($($nc(t)->getPrincipal()))->getName());
					if (serverPrincipal == nullptr || $nc(serverPrincipal)->equals(name)) {
						if (SubjectComber::DEBUG) {
							$init($System);
							$nc($System::out)->println($$str({"Found "_s, $(credClass->getSimpleName()), " for "_s, name}));
						}
						if (oneOnly) {
							return $of(t);
						} else {
							$nc(answer)->add($(credClass->cast(t)));
						}
					}
				}
			} else {
				$load($KerberosTicket);
				if (credClass == $KerberosTicket::class$) {
					$var($Set, pcs, $nc(subject)->getPrivateCredentials());
					$synchronized(pcs) {
						$var($Iterator, iterator, $nc(pcs)->iterator());
						while ($nc(iterator)->hasNext()) {
							$var($Object, obj, iterator->next());
							if ($instanceOf($KerberosTicket, obj)) {
								$var($KerberosTicket, ticket, $cast($KerberosTicket, obj));
								if (SubjectComber::DEBUG) {
									$init($System);
									$var($String, var$2, $$str({"Found ticket for "_s, $($nc(ticket)->getClient()), " to go to "_s}));
									$var($String, var$1, $$concat(var$2, $(ticket->getServer())));
									$var($String, var$0, $$concat(var$1, " expiring on "));
									$nc($System::out)->println($$concat(var$0, $(ticket->getEndTime())));
								}
								if (!$nc(ticket)->isCurrent()) {
									if (!subject->isReadOnly()) {
										iterator->remove();
										try {
											ticket->destroy();
											if (SubjectComber::DEBUG) {
												$init($System);
												$nc($System::out)->println($$str({"Removed and destroyed the expired Ticket \n"_s, ticket}));
											}
										} catch ($DestroyFailedException&) {
											$var($DestroyFailedException, dfe, $catch());
											if (SubjectComber::DEBUG) {
												$init($System);
												$nc($System::out)->println($$str({"Expired ticket not detroyed successfully. "_s, dfe}));
											}
										}
									}
								} else {
									$var($KerberosPrincipal, serverAlias, $nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketGetServerAlias(ticket));
									bool var$3 = serverPrincipal == nullptr || $nc($($nc($(ticket->getServer()))->getName()))->equals(serverPrincipal);
									if (var$3 || (serverAlias != nullptr && $nc(serverPrincipal)->equals($(serverAlias->getName())))) {
										$var($KerberosPrincipal, clientAlias, $nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketGetClientAlias(ticket));
										bool var$4 = clientPrincipal == nullptr || $nc(clientPrincipal)->equals($($nc($(ticket->getClient()))->getName()));
										if (var$4 || (clientAlias != nullptr && $nc(clientPrincipal)->equals($(clientAlias->getName())))) {
											if (oneOnly) {
												return $of(ticket);
											} else {
												if (clientPrincipal == nullptr) {
													if (clientAlias == nullptr) {
														$assign(clientPrincipal, $nc($(ticket->getClient()))->getName());
													} else {
														$assign(clientPrincipal, clientAlias->getName());
													}
												}
												if (serverPrincipal == nullptr) {
													if (serverAlias == nullptr) {
														$assign(serverPrincipal, $nc($(ticket->getServer()))->getName());
													} else {
														$assign(serverPrincipal, serverAlias->getName());
													}
												}
												$nc(answer)->add($(credClass->cast(ticket)));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return $of(answer);
	}
}

void clinit$SubjectComber($Class* class$) {
	$init($Krb5Util);
	SubjectComber::DEBUG = $Krb5Util::DEBUG;
}

SubjectComber::SubjectComber() {
}

$Class* SubjectComber::load$($String* name, bool initialize) {
	$loadClass(SubjectComber, name, initialize, &_SubjectComber_ClassInfo_, clinit$SubjectComber, allocate$SubjectComber);
	return class$;
}

$Class* SubjectComber::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun