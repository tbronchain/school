<?php


interface People
{
  public function getName();
}

class PeopleImpl implements People
{
  public function getName()
  {
    return 'Guy Liguili';
  }
}

$a = new PeopleImpl();
echo "Nom : ".$a->getName()."\n";

?>