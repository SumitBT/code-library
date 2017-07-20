package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Beacon;

public interface BeaconRepo extends CrudRepository<Beacon, Long>
{	
}