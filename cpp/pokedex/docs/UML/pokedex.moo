<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{A2BD3C35-BC2E-4D00-888F-E9A6F0F9D112}" Label="" LastModificationDate="1289713122" Name="pokedex" Objects="171" Symbols="26" Target="C++" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>A2BD3C35-BC2E-4D00-888F-E9A6F0F9D112</a:ObjectID>
<a:Name>pokedex</a:Name>
<a:Code>pokedex</a:Code>
<a:CreationDate>1289661420</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289712830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:PackageOptionsText>[FolderOptions]

[FolderOptions\Class Diagram Objects]
GenerationCheckModel=Yes
GenerationPath=
GenerationOptions=
GenerationTasks=
GenerationTargets=
GenerationSelections=</a:PackageOptionsText>
<a:ModelOptionsText>[ModelOptions]

[ModelOptions\Cld]
CaseSensitive=Yes
DisplayName=Yes
EnableTrans=No
EnableRequirements=No
ShowClss=No
DeftAttr=int
DeftMthd=int
DeftParm=int
DeftCont=
DomnDttp=Yes
DomnChck=No
DomnRule=No
SupportDelay=No
PreviewEditable=Yes
AutoRealize=No
DttpFullName=Yes
DeftClssAttrVisi=private
VBNetPreprocessingSymbols=
CSharpPreprocessingSymbols=

[ModelOptions\Cld\NamingOptionsTemplates]

[ModelOptions\Cld\ClssNamingOptions]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN]

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS]

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF]

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR]

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS]

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT]

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG]

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP]

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR]

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD]

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM]

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT]

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART]

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC]

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC]

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK]

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK]

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK]

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK]

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV]

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST]

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT]

[ModelOptions\Cld\ClssNamingOptions\STAT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE]

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI]

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC]

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR]

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO]

[ModelOptions\Cld\ClssNamingOptions\FILO\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=&quot;\/:*?&lt;&gt;|&quot;
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_. &quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ]

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK]

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass]

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Generate]

[ModelOptions\Generate\Cdm]
CheckModel=Yes
SaveLinks=Yes
NameToCode=No
Notation=2

[ModelOptions\Generate\Pdm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No
BuildTrgr=No
TablePrefix=
RefrUpdRule=RESTRICT
RefrDelRule=RESTRICT
IndxPKName=%TABLE%_PK
IndxAKName=%TABLE%_AK
IndxFKName=%REFR%_FK
IndxThreshold=
ColnFKName=%.3:PARENT%_%COLUMN%
ColnFKNameUse=No

[ModelOptions\Generate\Xsm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No</a:ModelOptionsText>
<c:ObjectLanguage>
<o:Shortcut Id="o3">
<a:ObjectID>D81E9B72-76FF-4C1F-9B9F-6D3CA550421B</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1289661420</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661420</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:ClassDiagrams>
<o:ClassDiagram Id="o4">
<a:ObjectID>ADE4E402-8CCC-4DF3-9138-DBFAE5313963</a:ObjectID>
<a:Name>DiagrammeClasses_1</a:Name>
<a:Code>DiagrammeClasses_1</a:Code>
<a:CreationDate>1289661420</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289712936</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\CLD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=No
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=2
Trunc Length=40
Word Length=40
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom de l&amp;#39;objet&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Commentaire&quot; Attribute=&quot;Comment&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;LEFT&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=&lt;Form&gt;[CRLF] &lt;Form Name=&quot;Centre&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF]  &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Source&quot; &gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Destination&quot; &gt;[CRLF] &lt;/Form&gt;[CRLF]&lt;/Form&gt;
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;ExclusiveChoice Name=&quot;Choix exclusif&quot; Mandatory=&quot;Yes&quot; Display=&quot;HorizontalRadios&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF]  &lt;StandardAttribute Name=&quot;Emplacement&quot; Attribute=&quot;LocationOrName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/ExclusiveChoice&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Class.IconPicture=No
Class_SymbolLayout=
Interface.IconPicture=No
Interface_SymbolLayout=
Port.IconPicture=No
Port_SymbolLayout=
ClssShowSttr=Yes
Class.Comment=No
ClssShowCntr=Yes
ClssShowAttr=Yes
ClssAttrTrun=No
ClssAttrMax=3
ClssShowMthd=Yes
ClssMthdTrun=No
ClssMthdMax=3
ClssShowInnr=Yes
IntfShowSttr=Yes
Interface.Comment=No
IntfShowAttr=Yes
IntfAttrTrun=No
IntfAttrMax=3
IntfShowMthd=Yes
IntfMthdTrun=No
IntfMthdMax=3
IntfShowCntr=Yes
IntfShowInnr=Yes
PortShowName=Yes
PortShowType=No
PortShowMult=No
AttrShowVisi=Yes
AttrVisiFmt=1
AttrShowStrn=Yes
AttrShowDttp=Yes
AttrShowDomn=No
AttrShowInit=Yes
MthdShowVisi=Yes
MthdVisiFmt=1
MthdShowStrn=Yes
MthdShowRttp=Yes
MthdShowParm=Yes
AsscShowName=No
AsscShowCntr=Yes
AsscShowRole=Yes
AsscShowOrdr=Yes
AsscShowMult=Yes
AsscMultStr=Yes
AsscShowStrn=No
GnrlShowName=No
GnrlShowStrn=Yes
GnrlShowCntr=Yes
RlzsShowName=No
RlzsShowStrn=Yes
RlzsShowCntr=Yes
DepdShowName=No
DepdShowStrn=Yes
DepdShowCntr=Yes
RqlkShowName=No
RqlkShowStrn=Yes
RqlkShowCntr=Yes

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=1
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDCLASS]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
CNTRFont=Arial,8,N
CNTRFont color=0, 0, 0
AttributesFont=Arial,8,N
AttributesFont color=0, 0, 0
ClassPrimaryAttributeFont=Arial,8,U
ClassPrimaryAttributeFont color=0, 0, 0
OperationsFont=Arial,8,N
OperationsFont color=0, 0, 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=174 228 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDINTF]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
CNTRFont=Arial,8,N
CNTRFont color=0, 0, 0
AttributesFont=Arial,8,N
AttributesFont color=0, 0, 0
OperationsFont=Arial,8,N
OperationsFont color=0, 0, 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=208 208 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMPORT]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=800
Height=800
Brush color=174 228 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDASSC]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
MULAFont=Arial,8,N
MULAFont color=0, 0, 0
Line style=1
Pen=1 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\INNERLINK]
Line style=1
Pen=1 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDACLK]
Line style=1
Pen=2 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\GNRLLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
Line style=1
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RLZSLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
Line style=1
Pen=3 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RQLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
Line style=1
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\DEPDLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
Line style=1
Pen=2 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0, 0, 0
Line style=1
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0, 0, 0
Line style=0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8268, 11693)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>15</a:PaperSource>
<c:Symbols>
<o:NoteSymbol Id="o5">
<a:Text>widget creation d&#39;un proprietaire</a:Text>
<a:CreationDate>1289712818</a:CreationDate>
<a:ModificationDate>1289712989</a:ModificationDate>
<a:Rect>((17701,75123), (24150,79445))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
<a:ManuallyResized>1</a:ManuallyResized>
</o:NoteSymbol>
<o:NoteSymbol Id="o6">
<a:Text>widget creation d&#39;une equipe</a:Text>
<a:CreationDate>1289712819</a:CreationDate>
<a:ModificationDate>1289713014</a:ModificationDate>
<a:Rect>((17851,63695), (22650,67294))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
</o:NoteSymbol>
<o:NoteSymbol Id="o7">
<a:Text>widget affichage des differentes equipes du proprio</a:Text>
<a:CreationDate>1289712821</a:CreationDate>
<a:ModificationDate>1289713041</a:ModificationDate>
<a:Rect>((45902,50296), (55124,55220))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
<a:ManuallyResized>1</a:ManuallyResized>
</o:NoteSymbol>
<o:NoteSymbol Id="o8">
<a:Text>widget affichage informations pokemons
</a:Text>
<a:CreationDate>1289712823</a:CreationDate>
<a:ModificationDate>1289712901</a:ModificationDate>
<a:Rect>((-448,44859), (5926,50345))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
<a:ManuallyResized>1</a:ManuallyResized>
</o:NoteSymbol>
<o:NoteSymbol Id="o9">
<a:Text>widget affichage des differents pokemons faisant partie de l&#39;equipe</a:Text>
<a:CreationDate>1289712825</a:CreationDate>
<a:ModificationDate>1289713051</a:ModificationDate>
<a:Rect>((32777,12318), (42001,18196))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
<a:ManuallyResized>1</a:ManuallyResized>
</o:NoteSymbol>
<o:NoteSymbol Id="o10">
<a:Text>Pokedex / GUI
</a:Text>
<a:CreationDate>1289712936</a:CreationDate>
<a:ModificationDate>1289712964</a:ModificationDate>
<a:Rect>((-15825,80748), (-7651,84347))</a:Rect>
<a:TextStyle>4130</a:TextStyle>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16711680</a:LineColor>
<a:FillColor>16777215</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontName>Arial,8,N</a:FontName>
<a:ManuallyResized>1</a:ManuallyResized>
</o:NoteSymbol>
<o:AssociationSymbol Id="o11">
<a:CreationDate>1289662279</a:CreationDate>
<a:ModificationDate>1289713122</a:ModificationDate>
<a:SourceTextOffset>(1050, -2237)</a:SourceTextOffset>
<a:Rect>((-2797,-32543), (-489,-12333))</a:Rect>
<a:ListOfPoints>((-2797,-12333),(-2797,-18584),(-526,-18584),(-526,-32543))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o12"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o13"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o14"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o15">
<a:CreationDate>1289711194</a:CreationDate>
<a:ModificationDate>1289711194</a:ModificationDate>
<a:Rect>((-15487,-32557), (-8738,-12907))</a:Rect>
<a:ListOfPoints>((-9825,-12907),(-9825,-22544),(-13650,-22544),(-13650,-32557))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o12"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o16"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o17"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o18">
<a:CreationDate>1289711229</a:CreationDate>
<a:ModificationDate>1289711248</a:ModificationDate>
<a:Rect>((-7274,38374), (-1876,55923))</a:Rect>
<a:ListOfPoints>((-3000,55923),(-3000,46003),(-5400,46003),(-5400,38374))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o12"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o20"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o21">
<a:CreationDate>1289711692</a:CreationDate>
<a:ModificationDate>1289712997</a:ModificationDate>
<a:Rect>((11475,70797), (54975,75192))</a:Rect>
<a:ListOfPoints>((11475,74018),(24476,74018),(24476,71971),(54975,71971))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o22"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o23"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o24">
<a:CreationDate>1289711698</a:CreationDate>
<a:ModificationDate>1289711703</a:ModificationDate>
<a:Rect>((42563,39946), (54111,66196))</a:Rect>
<a:ListOfPoints>((52987,66196),(52987,56002),(44437,56002),(44437,39946))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o22"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o25"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o26"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o27">
<a:CreationDate>1289711700</a:CreationDate>
<a:ModificationDate>1289711700</a:ModificationDate>
<a:Rect>((11475,37696), (34800,63920))</a:Rect>
<a:ListOfPoints>((11475,62745),(34800,62746),(34800,37696))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o25"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o28"/>
</c:Object>
</o:AssociationSymbol>
<o:GeneralizationSymbol Id="o29">
<a:CreationDate>1289711892</a:CreationDate>
<a:ModificationDate>1289711941</a:ModificationDate>
<a:Rect>((-2556,75467), (0,96228))</a:Rect>
<a:ListOfPoints>((0,75467),(0,84001),(-2556,84001),(-2556,96228))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>16744576</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o30"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o31"/>
</c:Object>
</o:GeneralizationSymbol>
<o:AssociationSymbol Id="o32">
<a:CreationDate>1289712483</a:CreationDate>
<a:ModificationDate>1289712483</a:ModificationDate>
<a:Rect>((7200,11584), (43949,35509))</a:Rect>
<a:ListOfPoints>((42825,35509),(42825,11584),(7200,11584))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o25"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o12"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o33"/>
</c:Object>
</o:AssociationSymbol>
<o:ClassSymbol Id="o12">
<a:CreationDate>1289661446</a:CreationDate>
<a:ModificationDate>1289710642</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-19314,-16317), (16012,43993))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o34"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o13">
<a:CreationDate>1289662148</a:CreationDate>
<a:ModificationDate>1289711093</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-6460,-35914), (5408,-29172))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o35"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o19">
<a:CreationDate>1289709508</a:CreationDate>
<a:ModificationDate>1289711248</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-19630,53638), (14382,79860))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o36"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o16">
<a:CreationDate>1289711139</a:CreationDate>
<a:ModificationDate>1289711182</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-18042,-35515), (-9108,-28773))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o37"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o22">
<a:CreationDate>1289711301</a:CreationDate>
<a:ModificationDate>1289711703</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((38770,64409), (64132,75047))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o38"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o25">
<a:CreationDate>1289711467</a:CreationDate>
<a:ModificationDate>1289711681</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((28173,31937), (62727,45495))</a:Rect>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o39"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o30">
<a:CreationDate>1289711827</a:CreationDate>
<a:ModificationDate>1289711941</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-8700,89089), (4725,98302))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>16744448</a:LineColor>
<a:FillColor>16770222</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Class Ref="o40"/>
</c:Object>
</o:ClassSymbol>
</c:Symbols>
</o:ClassDiagram>
</c:ClassDiagrams>
<c:DefaultDiagram>
<o:ClassDiagram Ref="o4"/>
</c:DefaultDiagram>
<c:Classes>
<o:Class Id="o34">
<a:ObjectID>DDEA01A1-1FB5-4FEF-88CB-C6A7E6A531D3</a:ObjectID>
<a:Name>Pokemon</a:Name>
<a:Code>Pokemon</a:Code>
<a:CreationDate>1289661446</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289712492</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o41">
<a:ObjectID>871B9ADE-EAEE-4A83-8BBF-7225EEEFAD92</a:ObjectID>
<a:Name>id</a:Name>
<a:Code>id</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289662043</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o42">
<a:ObjectID>C39E0BFE-015E-4104-966F-860CA9B0FBE4</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o43">
<a:ObjectID>97D07F85-4BF2-4857-9539-8376AAAAA0B7</a:ObjectID>
<a:Name>type</a:Name>
<a:Code>type</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>vector&lt;QString&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o44">
<a:ObjectID>DFBB9D70-8970-4C36-810C-BF841A680005</a:ObjectID>
<a:Name>exp</a:Name>
<a:Code>exp</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o45">
<a:ObjectID>E56ACC3A-6440-4019-BF11-E406A51B8836</a:ObjectID>
<a:Name>stats</a:Name>
<a:Code>stats</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>vector&lt;int&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o46">
<a:ObjectID>6541F1AE-AA7C-402D-8CB0-1912CA0A9278</a:ObjectID>
<a:Name>evolution</a:Name>
<a:Code>evolution</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::vector&lt;s_evo&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o47">
<a:ObjectID>04C47EBC-6F3C-4D13-9B56-EE6FA0DDBD87</a:ObjectID>
<a:Name>ratioMale</a:Name>
<a:Code>ratioMale</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>float</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o48">
<a:ObjectID>5B171982-5A8A-4A4E-8E51-0D1BDD9BDE4D</a:ObjectID>
<a:Name>ratioFemale</a:Name>
<a:Code>ratioFemale</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>float</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o49">
<a:ObjectID>1E93F513-3DB0-4A61-8EAA-B17E4022B3E8</a:ObjectID>
<a:Name>eggGroup</a:Name>
<a:Code>eggGroup</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::vector&lt;QString&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o50">
<a:ObjectID>97E99618-299D-4F35-87DA-F6CAC9C18EEC</a:ObjectID>
<a:Name>species</a:Name>
<a:Code>species</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>string</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o51">
<a:ObjectID>51FDB8F5-C4BA-4A9C-BC4E-64DC47730225</a:ObjectID>
<a:Name>height</a:Name>
<a:Code>height</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>float</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o52">
<a:ObjectID>485B7AA5-8A2B-4BCD-9CCC-88BD22F6AED1</a:ObjectID>
<a:Name>weight</a:Name>
<a:Code>weight</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>float</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o53">
<a:ObjectID>E675FB9B-537F-4829-87C8-2520F27FF9E7</a:ObjectID>
<a:Name>description</a:Name>
<a:Code>description</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:DataType>string</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o54">
<a:ObjectID>66DE8FCE-5D82-4DAC-BCF5-A2BF2F3336FA</a:ObjectID>
<a:Name>move</a:Name>
<a:Code>move</a:Code>
<a:CreationDate>1289661448</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::vector&lt;s_move&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o55">
<a:ObjectID>CDFAB405-C4B9-43BB-867A-32C5C8270DE1</a:ObjectID>
<a:Name>ability</a:Name>
<a:Code>ability</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o56">
<a:ObjectID>166E5EBC-9683-462C-9145-922E84D39129</a:ObjectID>
<a:Name>image</a:Name>
<a:Code>image</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o57">
<a:ObjectID>05AC6A35-38E4-49BC-A89D-2AB1A09CCCA9</a:ObjectID>
<a:Name>Pokemon</a:Name>
<a:Code>Pokemon</a:Code>
<a:CreationDate>1289661921</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o58">
<a:ObjectID>7CE1BFCB-2E81-4CE6-AD3A-7A7F045D5075</a:ObjectID>
<a:Name>~Pokemon</a:Name>
<a:Code>~Pokemon</a:Code>
<a:CreationDate>1289661921</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o59">
<a:ObjectID>EDBFAF31-D2CD-4E35-882B-F78DB7367D78</a:ObjectID>
<a:Name>Pokemon</a:Name>
<a:Code>Pokemon</a:Code>
<a:CreationDate>1289661923</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o60">
<a:ObjectID>66A684EA-CB47-4AAE-A53E-681EA365D159</a:ObjectID>
<a:Name>oldPokemon</a:Name>
<a:Code>oldPokemon</a:Code>
<a:CreationDate>1289661923</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>const Pokemon&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o34"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o61">
<a:ObjectID>7CEA5577-B68F-4DFF-B5B2-2BB75C8E7EEB</a:ObjectID>
<a:Name>getId</a:Name>
<a:Code>getId</a:Code>
<a:CreationDate>1289661945</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>int</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o41"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o62">
<a:ObjectID>C50248DB-DDEB-4DCE-92BA-E118A6DBCBC9</a:ObjectID>
<a:Name>getName</a:Name>
<a:Code>getName</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>QString</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o42"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o63">
<a:ObjectID>5A3AE606-BB3C-4E62-9E1A-D790F90979B0</a:ObjectID>
<a:Name>setName</a:Name>
<a:Code>setName</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o64">
<a:ObjectID>BE902520-0FE1-4465-9413-65B592E2F30E</a:ObjectID>
<a:Name>newName</a:Name>
<a:Code>newName</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>QString</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o42"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o65">
<a:ObjectID>36CD6FA8-FCF4-459E-B1A2-3D15C77D5E30</a:ObjectID>
<a:Name>getType</a:Name>
<a:Code>getType</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>vector&lt;QString&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o43"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o66">
<a:ObjectID>1E575F9D-2ADF-4AE5-A1CE-635542032C18</a:ObjectID>
<a:Name>setType</a:Name>
<a:Code>setType</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o67">
<a:ObjectID>DD053A28-ED74-4464-B4F7-5548EB381E39</a:ObjectID>
<a:Name>newType</a:Name>
<a:Code>newType</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>vector&lt;QString&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o43"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o68">
<a:ObjectID>0852F27A-FF3A-4A22-9339-31EAC5B2A390</a:ObjectID>
<a:Name>getExp</a:Name>
<a:Code>getExp</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>int</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o44"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o69">
<a:ObjectID>36FDEC30-D735-4B28-A507-B26845A1EF9A</a:ObjectID>
<a:Name>setExp</a:Name>
<a:Code>setExp</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o70">
<a:ObjectID>D961B6C1-95BF-4CD4-A9CB-F7381F969C2C</a:ObjectID>
<a:Name>newExp</a:Name>
<a:Code>newExp</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>int</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o44"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o71">
<a:ObjectID>F171F11E-96B8-423D-9798-832EAE16C6E8</a:ObjectID>
<a:Name>getStats</a:Name>
<a:Code>getStats</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>vector&lt;int&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o45"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o72">
<a:ObjectID>75121048-AD2A-416B-8E04-E52059D689DC</a:ObjectID>
<a:Name>setStats</a:Name>
<a:Code>setStats</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o73">
<a:ObjectID>6D5EA193-BFFD-44D2-8F6A-98F98B870432</a:ObjectID>
<a:Name>newStats</a:Name>
<a:Code>newStats</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>vector&lt;int&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o45"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o74">
<a:ObjectID>D41D805D-2C7F-45C0-A731-EBF3AD1BC97D</a:ObjectID>
<a:Name>getEvolution</a:Name>
<a:Code>getEvolution</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>std::vector&lt;s_evo&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o46"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o75">
<a:ObjectID>1D13D05B-6792-40D7-B219-6C2629038883</a:ObjectID>
<a:Name>setEvolution</a:Name>
<a:Code>setEvolution</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o76">
<a:ObjectID>526B131C-9B49-4E32-81B5-A24623B8A62E</a:ObjectID>
<a:Name>newEvolution</a:Name>
<a:Code>newEvolution</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>std::vector&lt;s_evo&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o46"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o77">
<a:ObjectID>89BEDF14-C610-4B1F-81A9-E3DB6C08ECD7</a:ObjectID>
<a:Name>getRatioMale</a:Name>
<a:Code>getRatioMale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>float</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o47"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o78">
<a:ObjectID>05BADEDF-196A-4B65-8FB2-028A65C35C0F</a:ObjectID>
<a:Name>setRatioMale</a:Name>
<a:Code>setRatioMale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o79">
<a:ObjectID>9992802A-8F47-4FD0-922F-F38F01B1D27E</a:ObjectID>
<a:Name>newRatioMale</a:Name>
<a:Code>newRatioMale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>float</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o47"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o80">
<a:ObjectID>B4AD16E4-C364-4C4A-897E-40F6EC6B7E64</a:ObjectID>
<a:Name>getRatioFemale</a:Name>
<a:Code>getRatioFemale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>float</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o48"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o81">
<a:ObjectID>BCF20520-FCF8-4DB9-B42D-790DFF2D7490</a:ObjectID>
<a:Name>setRatioFemale</a:Name>
<a:Code>setRatioFemale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o82">
<a:ObjectID>B526632F-D593-402A-92B9-A3F9B93F3357</a:ObjectID>
<a:Name>newRatioFemale</a:Name>
<a:Code>newRatioFemale</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>float</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o48"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o83">
<a:ObjectID>E51DA316-F108-4AD9-9A51-4D9AB113E037</a:ObjectID>
<a:Name>getEggGroup</a:Name>
<a:Code>getEggGroup</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>std::vector&lt;QString&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o49"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o84">
<a:ObjectID>A065EB31-640C-42B7-8272-9C46FBC2040E</a:ObjectID>
<a:Name>setEggGroup</a:Name>
<a:Code>setEggGroup</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o85">
<a:ObjectID>02E8C357-24F5-4876-9827-7E0CC3D4EC89</a:ObjectID>
<a:Name>newEggGroup</a:Name>
<a:Code>newEggGroup</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>std::vector&lt;QString&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o49"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o86">
<a:ObjectID>6BA7EB91-3252-4DC9-8F51-E1CDD1BE4C43</a:ObjectID>
<a:Name>getSpecies</a:Name>
<a:Code>getSpecies</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>string</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o50"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o87">
<a:ObjectID>777C4704-C8DA-4CD2-83EF-6D5AC42CF1B7</a:ObjectID>
<a:Name>setSpecies</a:Name>
<a:Code>setSpecies</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o88">
<a:ObjectID>4073704B-354D-490C-8F0C-B2B1BCE047A7</a:ObjectID>
<a:Name>newSpecies</a:Name>
<a:Code>newSpecies</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o50"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o89">
<a:ObjectID>D67F531D-78FA-4CF8-8064-D2202DAF5384</a:ObjectID>
<a:Name>getHeight</a:Name>
<a:Code>getHeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>float</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o51"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o90">
<a:ObjectID>C07CF32F-B899-461B-A2B9-3722B306A7E6</a:ObjectID>
<a:Name>setHeight</a:Name>
<a:Code>setHeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o91">
<a:ObjectID>575235A1-B36D-4208-88D6-2735EFF989AC</a:ObjectID>
<a:Name>newHeight</a:Name>
<a:Code>newHeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>float</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o51"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o92">
<a:ObjectID>EEFC92AF-B112-4AEE-8ABF-737750526000</a:ObjectID>
<a:Name>getWeight</a:Name>
<a:Code>getWeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>float</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o52"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o93">
<a:ObjectID>65837A9D-D04F-426E-8814-A12BD314307D</a:ObjectID>
<a:Name>setWeight</a:Name>
<a:Code>setWeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o94">
<a:ObjectID>E70F0458-2BAF-4C58-8DAD-3CBF0653A8D9</a:ObjectID>
<a:Name>newWeight</a:Name>
<a:Code>newWeight</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>float</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o52"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o95">
<a:ObjectID>C4502DE3-A811-459E-BE50-88A556C156F6</a:ObjectID>
<a:Name>getDescription</a:Name>
<a:Code>getDescription</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>string</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o53"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o96">
<a:ObjectID>D13AB7BE-33BF-4704-9CE9-AFB8126397A5</a:ObjectID>
<a:Name>setDescription</a:Name>
<a:Code>setDescription</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o97">
<a:ObjectID>A53C04E4-332B-41F1-B7AF-8B57845DA696</a:ObjectID>
<a:Name>newDescription</a:Name>
<a:Code>newDescription</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661963</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:Parameter.DataType>string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o53"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o98">
<a:ObjectID>8E3879CA-38D9-40C5-8E8D-F3B52CA6EC99</a:ObjectID>
<a:Name>getMove</a:Name>
<a:Code>getMove</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>std::vector&lt;s_move&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o54"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o99">
<a:ObjectID>8B288B2E-5240-461D-A593-345ED5EA097A</a:ObjectID>
<a:Name>setMove</a:Name>
<a:Code>setMove</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o100">
<a:ObjectID>BD933DCB-94B2-405D-B883-40C24D4BDB95</a:ObjectID>
<a:Name>newMove</a:Name>
<a:Code>newMove</a:Code>
<a:CreationDate>1289661958</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>std::vector&lt;s_move&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o54"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o101">
<a:ObjectID>92FE9866-F4A5-4A98-98C8-F6D444E779BC</a:ObjectID>
<a:Name>getEvoByLevel</a:Name>
<a:Code>getEvoByLevel</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710875</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const QString</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o102">
<a:ObjectID>4C34F1AC-54B4-4D34-9A2E-7734DA6BC783</a:ObjectID>
<a:Name>level</a:Name>
<a:Code>level</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710875</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const int&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o103">
<a:ObjectID>AAD47AC1-7A75-4C22-A695-9B2BE4768128</a:ObjectID>
<a:Name>getEvoLevels</a:Name>
<a:Code>getEvoLevels</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::vector&lt;s_evo&gt;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o104">
<a:ObjectID>1AAB2A9B-208E-44D5-819D-9D7A7BE13B9E</a:ObjectID>
<a:Name>getEvoSpecials</a:Name>
<a:Code>getEvoSpecials</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710852</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::vector&lt;s_evo&gt;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o105">
<a:ObjectID>CE2058A6-5830-472B-8DDC-DB97F72F5910</a:ObjectID>
<a:Name>getMoveByLevel</a:Name>
<a:Code>getMoveByLevel</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710892</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::vector&lt;s_move&gt;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o106">
<a:ObjectID>0E4F95A8-CF84-4864-9234-D13078DD113C</a:ObjectID>
<a:Name>level</a:Name>
<a:Code>level</a:Code>
<a:CreationDate>1289710882</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710892</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const int&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o107">
<a:ObjectID>F25B1D9B-5035-499F-9C73-8A75A51491BC</a:ObjectID>
<a:Name>getStatsSome</a:Name>
<a:Code>getStatsSome</a:Code>
<a:CreationDate>1289710649</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710908</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o108">
<a:ObjectID>D2FDE072-375A-4E0F-A6FB-E7B0767A1FF3</a:ObjectID>
<a:Name>stat</a:Name>
<a:Code>stat</a:Code>
<a:CreationDate>1289710898</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710908</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const STATS&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o109">
<a:ObjectID>B7703E19-4BE8-407B-956E-D075F13136B6</a:ObjectID>
<a:Name>addType</a:Name>
<a:Code>addType</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711087</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o110">
<a:ObjectID>C45D793E-2CA4-447E-99A0-AF04636FB6BA</a:ObjectID>
<a:Name>addEggGroup</a:Name>
<a:Code>addEggGroup</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711087</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o111">
<a:ObjectID>64FF21EC-432B-4F26-94EE-6CFDDF1BDAC1</a:ObjectID>
<a:Name>addStat</a:Name>
<a:Code>addStat</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711087</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o112">
<a:ObjectID>70E45BFD-22AA-43F9-82D8-8E81ADD17B74</a:ObjectID>
<a:Name>addEvo</a:Name>
<a:Code>addEvo</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711087</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o113">
<a:ObjectID>71D824B7-1CCB-4C7B-9CFD-E28F5C9284EE</a:ObjectID>
<a:Name>id</a:Name>
<a:Code>id</a:Code>
<a:CreationDate>1289710957</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711016</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>int</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o114">
<a:ObjectID>8DF38611-9D21-4784-83D9-2B7051F50F5A</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289710957</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711016</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>QString</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o115">
<a:ObjectID>ACCAE65B-3A9D-4434-8D7B-3790BCD29611</a:ObjectID>
<a:Name>condition</a:Name>
<a:Code>condition</a:Code>
<a:CreationDate>1289710957</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711016</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>QString</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o116">
<a:ObjectID>20169479-D807-4BD4-9BDC-DEC2F9F696E4</a:ObjectID>
<a:Name>level</a:Name>
<a:Code>level</a:Code>
<a:CreationDate>1289710957</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711016</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>int</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o117">
<a:ObjectID>6F21D118-FF5A-4D65-A491-572F4CCB032D</a:ObjectID>
<a:Name>addMove</a:Name>
<a:Code>addMove</a:Code>
<a:CreationDate>1289710853</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711087</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o118">
<a:ObjectID>54C1827F-06DD-462D-AC04-976FB598389E</a:ObjectID>
<a:Name>type</a:Name>
<a:Code>type</a:Code>
<a:CreationDate>1289711019</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711054</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>TYPE</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o119">
<a:ObjectID>79E160C4-537B-47C9-8895-805059C6A2C8</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289711019</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711054</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>QString</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o120">
<a:ObjectID>8925AB13-8F68-4A21-BC2D-6ADEFAE1A302</a:ObjectID>
<a:Name>machine</a:Name>
<a:Code>machine</a:Code>
<a:CreationDate>1289711019</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711054</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>MACHINE</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o121">
<a:ObjectID>E3F77AB5-FCD0-4DC7-9A47-4AD37D795196</a:ObjectID>
<a:Name>level</a:Name>
<a:Code>level</a:Code>
<a:CreationDate>1289711019</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711054</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>int</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o35">
<a:ObjectID>357E6C9B-1D1F-417C-B1E6-E34E42653CA7</a:ObjectID>
<a:Name>move</a:Name>
<a:Code>move</a:Code>
<a:CreationDate>1289662148</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711218</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o122">
<a:ObjectID>14E2E4F6-BC69-4E54-A42A-080B330C23C8</a:ObjectID>
<a:Name>type</a:Name>
<a:Code>type</a:Code>
<a:CreationDate>1289662149</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711133</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>enum TYPE</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o123">
<a:ObjectID>E4818AAF-22AF-4E4E-9418-70766B6ECECE</a:ObjectID>
<a:Name>machine</a:Name>
<a:Code>machine</a:Code>
<a:CreationDate>1289662149</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711133</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>enum MACHINE</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o124">
<a:ObjectID>292BD928-7939-4069-A8C7-1746418F6550</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289662149</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711133</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o125">
<a:ObjectID>BCA7AA96-DE5F-4844-8B77-E56374603819</a:ObjectID>
<a:Name>lvl</a:Name>
<a:Code>lvl</a:Code>
<a:CreationDate>1289662149</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711133</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
</o:Class>
<o:Class Id="o36">
<a:ObjectID>D861BDA6-E234-4533-8DD3-86E91D514BC0</a:ObjectID>
<a:Name>pokedex</a:Name>
<a:Code>pokedex</a:Code>
<a:CreationDate>1289709508</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712926</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Comment>pokedex / GUI</a:Comment>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o126">
<a:ObjectID>74B024D3-FF91-4880-9DE0-223D4A478C55</a:ObjectID>
<a:Name>_ui</a:Name>
<a:Code>_ui</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>Ui::pokedexClass</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o127">
<a:ObjectID>E3A83BFA-8A81-4852-ABA7-21A9CA3C7175</a:ObjectID>
<a:Name>_dom</a:Name>
<a:Code>_dom</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QDomDocument*</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o128">
<a:ObjectID>D25A6ABD-888E-4643-851F-2C797F3EF2FB</a:ObjectID>
<a:Name>_xml_doc</a:Name>
<a:Code>_xml_doc</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QFile*</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o129">
<a:ObjectID>E7830BE2-85B5-4872-8623-7E0ABCE21431</a:ObjectID>
<a:Name>_pokemons</a:Name>
<a:Code>_pokemons</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::vector&lt;pokemon&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o130">
<a:ObjectID>6A1D0851-F21F-4485-B276-0D01A1E7EA93</a:ObjectID>
<a:Name>_owners</a:Name>
<a:Code>_owners</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::list&lt;owner&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o131">
<a:ObjectID>496183B6-9FEA-40C2-BE8D-F3C8228AFB9F</a:ObjectID>
<a:Name>_teams</a:Name>
<a:Code>_teams</a:Code>
<a:CreationDate>1289709510</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709830</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::list&lt;team&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o132">
<a:ObjectID>2A54BF2E-B59D-4C2A-AB7A-FBEEA554D8DE</a:ObjectID>
<a:Name>pokedex</a:Name>
<a:Code>pokedex</a:Code>
<a:CreationDate>1289709797</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712926</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o36"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o133">
<a:ObjectID>3A66F629-1C48-45B2-801C-AF505A75BE2F</a:ObjectID>
<a:Name>~pokedex</a:Name>
<a:Code>~pokedex</a:Code>
<a:CreationDate>1289709797</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712926</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o36"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o134">
<a:ObjectID>46A8B70C-908C-43C4-B75F-EE971731C32A</a:ObjectID>
<a:Name>pokedex</a:Name>
<a:Code>pokedex</a:Code>
<a:CreationDate>1289709800</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712926</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o135">
<a:ObjectID>73DBCB06-4AC7-46ED-BE4F-AE75CF6AB9C5</a:ObjectID>
<a:Name>oldpokedex</a:Name>
<a:Code>oldpokedex</a:Code>
<a:CreationDate>1289709800</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712926</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const pokedex&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o36"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o36"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o136">
<a:ObjectID>5C60CD0B-845A-4CF0-A04F-29030309C910</a:ObjectID>
<a:Name>operator=</a:Name>
<a:Code>operator_</a:Code>
<a:CreationDate>1289709830</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709948</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>pokedex&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o36"/>
</c:ObjectReturnType>
</o:Operation>
<o:Operation Id="o137">
<a:ObjectID>FE3C72C3-4F7C-4299-A78D-775F6B5DC5E4</a:ObjectID>
<a:Name>addPokemonAttributesRec</a:Name>
<a:Code>addPokemonAttributesRec</a:Code>
<a:CreationDate>1289709830</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709978</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o138">
<a:ObjectID>BC375231-3A89-469F-8061-9A3C4EB99929</a:ObjectID>
<a:Name>noeud</a:Name>
<a:Code>noeud</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709978</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>QDomNode&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o139">
<a:ObjectID>E6FB2D1F-05F0-471C-BF9B-DC678D5A91FC</a:ObjectID>
<a:Name>poke</a:Name>
<a:Code>poke</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289709978</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>pokemon&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o140">
<a:ObjectID>EC95196A-3987-4E89-B161-35845D61C618</a:ObjectID>
<a:Name>parse</a:Name>
<a:Code>parse</a:Code>
<a:CreationDate>1289709830</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710081</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o141">
<a:ObjectID>85B93083-465B-427A-9B97-859CE4688F68</a:ObjectID>
<a:Name>displayListPok</a:Name>
<a:Code>displayListPok</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710081</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o142">
<a:ObjectID>232134D5-9A50-4506-8187-2EB71A254B5A</a:ObjectID>
<a:Name>displayInfoPok</a:Name>
<a:Code>displayInfoPok</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710081</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o143">
<a:ObjectID>BC550474-979C-4262-AFE5-AD15F7B1CE91</a:ObjectID>
<a:Name>addTeam</a:Name>
<a:Code>addTeam</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o144">
<a:ObjectID>33891F08-F120-4D23-8125-80B91D8AF79E</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710111</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const QString&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o145">
<a:ObjectID>5AA04E4A-A6C9-419B-97B6-BF4F2462B12F</a:ObjectID>
<a:Name>owner</a:Name>
<a:Code>owner</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710111</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const owner&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o146">
<a:ObjectID>77483A4C-92C3-4794-A880-031FBDD0D67A</a:ObjectID>
<a:Name>delTeam</a:Name>
<a:Code>delTeam</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o147">
<a:ObjectID>83A427CE-DEB7-4DDC-87C5-AA389EAC684C</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289710116</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710128</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const QString&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o148">
<a:ObjectID>09D3FD48-184C-4885-B3A4-9BF36288CE2A</a:ObjectID>
<a:Name>getTeam</a:Name>
<a:Code>getTeam</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710160</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const team&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o149">
<a:ObjectID>DE089BA3-8A0C-406F-B18C-82091B1A9C8A</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289710142</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710160</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const QString&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o150">
<a:ObjectID>CCC89A5F-18FF-41AF-8104-79131769BE68</a:ObjectID>
<a:Name>getTeams</a:Name>
<a:Code>getTeams</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710081</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::list&lt;team&gt;&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o151">
<a:ObjectID>DB359345-1549-4DE1-9C23-A1FAD75BEC88</a:ObjectID>
<a:Name>getTeamsOwner</a:Name>
<a:Code>getTeamsOwner</a:Code>
<a:CreationDate>1289709948</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710194</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::list&lt;team&gt;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o152">
<a:ObjectID>F56F0F52-BD66-4507-A43C-5935C0ADC91F</a:ObjectID>
<a:Name>owner</a:Name>
<a:Code>owner</a:Code>
<a:CreationDate>1289710170</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710194</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const owner&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o153">
<a:ObjectID>88F0C0C0-E9A1-4DB7-9087-91AC95C6E59D</a:ObjectID>
<a:Name>addOwner</a:Name>
<a:Code>addOwner</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o154">
<a:ObjectID>B7FDCC07-9AD5-4B0A-BE47-CED890907B79</a:ObjectID>
<a:Name>delOwner</a:Name>
<a:Code>delOwner</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o155">
<a:ObjectID>5CCEAD6A-7527-4BAC-8C82-68136F1A6C25</a:ObjectID>
<a:Name>getOwners</a:Name>
<a:Code>getOwners</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const std::list&lt;owner&gt;&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o156">
<a:ObjectID>4DFBB4D0-7127-4A13-A53B-9F2FD4392907</a:ObjectID>
<a:Name>getOwner</a:Name>
<a:Code>getOwner</a:Code>
<a:CreationDate>1289710081</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289710628</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>const owner&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o37">
<a:ObjectID>6C0B9666-6474-4C85-83DD-43B14D630403</a:ObjectID>
<a:Name>evo</a:Name>
<a:Code>evo</a:Code>
<a:CreationDate>1289711139</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711178</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o157">
<a:ObjectID>B40193E5-8B90-4A7C-95D7-947B29D7E4CA</a:ObjectID>
<a:Name>id</a:Name>
<a:Code>id</a:Code>
<a:CreationDate>1289711139</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711178</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o158">
<a:ObjectID>AD653B84-C45E-4800-A80A-CB07C094A9BE</a:ObjectID>
<a:Name>condition</a:Name>
<a:Code>condition</a:Code>
<a:CreationDate>1289711139</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711178</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o159">
<a:ObjectID>BFD0AE8A-2F2A-4E1F-BA8C-E5BD8469C5C5</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1289711139</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711139</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o160">
<a:ObjectID>CD612145-4CBC-48E3-9B1F-7FF757CA84E6</a:ObjectID>
<a:Name>lvl</a:Name>
<a:Code>lvl</a:Code>
<a:CreationDate>1289711139</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711139</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
</o:Class>
<o:Class Id="o38">
<a:ObjectID>BA7126BD-D446-4F91-A1D9-96196566765A</a:ObjectID>
<a:Name>owner</a:Name>
<a:Code>owner</a:Code>
<a:CreationDate>1289711301</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711734</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o161">
<a:ObjectID>663D4FFB-639D-4DBD-A9E3-0EDE6B41B5C2</a:ObjectID>
<a:Name>_oname</a:Name>
<a:Code>_oname</a:Code>
<a:CreationDate>1289711376</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711462</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o162">
<a:ObjectID>72256FA7-B292-4EAC-AD43-E3DC44D47932</a:ObjectID>
<a:Name>_avatar</a:Name>
<a:Code>_avatar</a:Code>
<a:CreationDate>1289711376</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711443</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o163">
<a:ObjectID>D4A7C364-DFA2-43ED-B002-EFEA3CEB2C0E</a:ObjectID>
<a:Name>owner</a:Name>
<a:Code>owner</a:Code>
<a:CreationDate>1289711339</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711351</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o38"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o164">
<a:ObjectID>F135C74C-D8F7-40D4-AEB1-323473FCE951</a:ObjectID>
<a:Name>~owner</a:Name>
<a:Code>~owner</a:Code>
<a:CreationDate>1289711339</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711351</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o38"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o165">
<a:ObjectID>8D3D3A80-0555-496F-9D65-C6815BC806A9</a:ObjectID>
<a:Name>owner</a:Name>
<a:Code>owner</a:Code>
<a:CreationDate>1289711344</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711351</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o166">
<a:ObjectID>ED9474CC-C609-4053-844F-1A79EA16B596</a:ObjectID>
<a:Name>oldOwner</a:Name>
<a:Code>oldOwner</a:Code>
<a:CreationDate>1289711344</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711351</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const owner&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o38"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o38"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o167">
<a:ObjectID>2545B07A-A223-4610-8022-EBFB8CA65B1C</a:ObjectID>
<a:Name>operator=</a:Name>
<a:Code>operator_</a:Code>
<a:CreationDate>1289711351</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711393</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>owner&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o38"/>
</c:ObjectReturnType>
<c:Parameters>
<o:Parameter Id="o168">
<a:ObjectID>02ECFF76-A34B-45C5-91BF-F16EA27301CC</a:ObjectID>
<a:Name>right</a:Name>
<a:Code>right</a:Code>
<a:CreationDate>1289711380</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711393</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const owner&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o38"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o169">
<a:ObjectID>06A6F7E6-5D87-49D6-9312-7766211887EF</a:ObjectID>
<a:Name>get_avatar</a:Name>
<a:Code>get_avatar</a:Code>
<a:CreationDate>1289711442</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711443</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>QString</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o162"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o170">
<a:ObjectID>31C6387F-5108-40A7-B52F-FBD416C478A1</a:ObjectID>
<a:Name>set_avatar</a:Name>
<a:Code>set_avatar</a:Code>
<a:CreationDate>1289711442</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711443</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o171">
<a:ObjectID>9E9505A4-4FCA-430A-8373-CF180DA62F5D</a:ObjectID>
<a:Name>new_avatar</a:Name>
<a:Code>new_avatar</a:Code>
<a:CreationDate>1289711442</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711443</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>QString</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o162"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o172">
<a:ObjectID>34398A88-36D0-4252-9527-A050D8FF97B2</a:ObjectID>
<a:Name>get_oname</a:Name>
<a:Code>get_oname</a:Code>
<a:CreationDate>1289711451</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711452</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>QString</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o161"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o39">
<a:ObjectID>A3069350-B3F7-4134-BEFD-8CBF8AD4F326</a:ObjectID>
<a:Name>team</a:Name>
<a:Code>team</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712492</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o173">
<a:ObjectID>5F6020DC-7F00-405E-916B-981BB3066CF7</a:ObjectID>
<a:Name>_tname</a:Name>
<a:Code>_tname</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>QString</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o174">
<a:ObjectID>55417E7A-B03D-4FD5-A3F1-C07EB830366B</a:ObjectID>
<a:Name>_owner</a:Name>
<a:Code>_owner</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>const owner*</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
<c:ObjectDataType>
<o:Class Ref="o38"/>
</c:ObjectDataType>
</o:Attribute>
<o:Attribute Id="o175">
<a:ObjectID>75FCFF8B-A2ED-4B3A-B7C9-01D639831CF0</a:ObjectID>
<a:Name>_pok</a:Name>
<a:Code>_pok</a:Code>
<a:CreationDate>1289711476</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:DataType>std::list&lt;const pokemon*&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o176">
<a:ObjectID>A194C114-F740-4563-B673-24561ECD50ED</a:ObjectID>
<a:Name>team</a:Name>
<a:Code>team</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o39"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o177">
<a:ObjectID>E6974ACF-19ED-40AC-BE0A-B517C259686A</a:ObjectID>
<a:Name>~team</a:Name>
<a:Code>~team</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o39"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o178">
<a:ObjectID>BC440149-87D8-442F-8C68-D5BFEDB83ED0</a:ObjectID>
<a:Name>team</a:Name>
<a:Code>team</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o179">
<a:ObjectID>F31ECB30-B236-4155-BCE8-43F8CAE072E1</a:ObjectID>
<a:Name>oldteam</a:Name>
<a:Code>oldteam</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const team&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o39"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o39"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o180">
<a:ObjectID>8C4ED9CF-5FE2-41BF-BCB5-343336F46E28</a:ObjectID>
<a:Name>operator=</a:Name>
<a:Code>operator_</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711467</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>team&amp;</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o39"/>
</c:ObjectReturnType>
<c:Parameters>
<o:Parameter Id="o181">
<a:ObjectID>3864D546-95FC-4126-9783-446E175CBA77</a:ObjectID>
<a:Name>right</a:Name>
<a:Code>right</a:Code>
<a:CreationDate>1289711467</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711467</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>const team&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o39"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o182">
<a:ObjectID>AAB0EE79-04F2-4876-9E23-4AD78037FEB3</a:ObjectID>
<a:Name>get_tname</a:Name>
<a:Code>get_tname</a:Code>
<a:CreationDate>1289711539</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>QString</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o173"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o183">
<a:ObjectID>A261DBE7-4938-41C0-B395-B1C81688C13C</a:ObjectID>
<a:Name>get_owner</a:Name>
<a:Code>get_owner</a:Code>
<a:CreationDate>1289711539</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>const owner*</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o38"/>
</c:ObjectReturnType>
<c:InfluentObject>
<o:Attribute Ref="o174"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o184">
<a:ObjectID>E8308CF8-B71B-47F2-91B8-2F99DF0C7D36</a:ObjectID>
<a:Name>get_pok</a:Name>
<a:Code>get_pok</a:Code>
<a:CreationDate>1289711539</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>std::list&lt;const pokemon*&gt;</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Attribute Ref="o175"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o185">
<a:ObjectID>999DEE6A-CE8C-47FC-97B9-09C274674C33</a:ObjectID>
<a:Name>set_pok</a:Name>
<a:Code>set_pok</a:Code>
<a:CreationDate>1289711539</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Stereotype>Setter</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o186">
<a:ObjectID>4B5D746C-3B99-4A1E-B206-ADCE9A9CE620</a:ObjectID>
<a:Name>new_pok</a:Name>
<a:Code>new_pok</a:Code>
<a:CreationDate>1289711539</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711552</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:Parameter.DataType>std::list&lt;const pokemon*&gt;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Attribute Ref="o175"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o40">
<a:ObjectID>605780F4-A435-41AB-B5E9-21CA7EDC7BEB</a:ObjectID>
<a:Name>QMainWindow</a:Name>
<a:Code>QMainWindow</a:Code>
<a:CreationDate>1289711827</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711936</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o187">
<a:ObjectID>9EB3B924-0188-47CB-8EB9-7975B419979D</a:ObjectID>
<a:Name>show</a:Name>
<a:Code>show</a:Code>
<a:CreationDate>1289711926</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712594</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
</c:Classes>
<c:Associations>
<o:Association Id="o14">
<a:ObjectID>501F0E19-12CB-4A33-A02D-8110DAE4C4EB</a:ObjectID>
<a:Name>Association_1</a:Name>
<a:Code>Association_1</a:Code>
<a:CreationDate>1289662279</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289711218</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o35"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o34"/>
</c:Object2>
</o:Association>
<o:Association Id="o17">
<a:ObjectID>16185929-40B4-485A-8280-D59DA1006ACF</a:ObjectID>
<a:Name>Association_2</a:Name>
<a:Code>Association_2</a:Code>
<a:CreationDate>1289711194</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711203</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o37"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o34"/>
</c:Object2>
</o:Association>
<o:Association Id="o20">
<a:ObjectID>81C1B8DB-33F2-4EBE-BCEC-1923517178ED</a:ObjectID>
<a:Name>Association_3</a:Name>
<a:Code>Association_3</a:Code>
<a:CreationDate>1289711229</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711239</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o34"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o36"/>
</c:Object2>
</o:Association>
<o:Association Id="o23">
<a:ObjectID>D3A1D915-C778-47CA-9B55-04B552F1BB4C</a:ObjectID>
<a:Name>Association_4</a:Name>
<a:Code>Association_4</a:Code>
<a:CreationDate>1289711692</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711716</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o38"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o36"/>
</c:Object2>
</o:Association>
<o:Association Id="o26">
<a:ObjectID>924A2C58-9F1C-4463-8D92-758811508431</a:ObjectID>
<a:Name>Association_5</a:Name>
<a:Code>Association_5</a:Code>
<a:CreationDate>1289711698</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711734</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o39"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o38"/>
</c:Object2>
</o:Association>
<o:Association Id="o28">
<a:ObjectID>77F3C6EC-7A91-4991-94F6-50443D389C34</a:ObjectID>
<a:Name>Association_6</a:Name>
<a:Code>Association_6</a:Code>
<a:CreationDate>1289711700</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711725</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o39"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o36"/>
</c:Object2>
</o:Association>
<o:Association Id="o33">
<a:ObjectID>940B67E4-DC26-49FA-9D24-BF4AD64D442F</a:ObjectID>
<a:Name>Association_7</a:Name>
<a:Code>Association_7</a:Code>
<a:CreationDate>1289712483</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289712492</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o34"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o39"/>
</c:Object2>
</o:Association>
</c:Associations>
<c:Generalizations>
<o:Generalization Id="o31">
<a:ObjectID>F59CCA8C-B692-4701-A187-F4B26DC4C1FB</a:ObjectID>
<a:Name>Generalisation_1</a:Name>
<a:Code>Generalisation_1</a:Code>
<a:CreationDate>1289711892</a:CreationDate>
<a:Creator>bronch_t</a:Creator>
<a:ModificationDate>1289711892</a:ModificationDate>
<a:Modifier>bronch_t</a:Modifier>
<c:Object1>
<o:Class Ref="o40"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o36"/>
</c:Object2>
</o:Generalization>
</c:Generalizations>
<c:TargetModels>
<o:TargetModel Id="o188">
<a:ObjectID>97C3F3FD-2738-4B47-99FE-3E52835512F7</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1289661420</a:CreationDate>
<a:Creator>rochel_a</a:Creator>
<a:ModificationDate>1289661420</a:ModificationDate>
<a:Modifier>rochel_a</a:Modifier>
<a:TargetModelURL>file:///%_OBJLANG%/C++.xol</a:TargetModelURL>
<a:TargetModelID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetModelID>
<a:TargetModelClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetModelClassID>
<c:SessionShortcuts>
<o:Shortcut Ref="o3"/>
</c:SessionShortcuts>
</o:TargetModel>
</c:TargetModels>
</o:Model>
</c:Children>
</o:RootObject>

</Model>