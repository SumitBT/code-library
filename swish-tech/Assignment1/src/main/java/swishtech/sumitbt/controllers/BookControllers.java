package swishtech.sumitbt.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import swishtech.sumitbt.models.Book;
import swishtech.sumitbt.models.User;
import swishtech.sumitbt.repositories.BookRepo;
import swishtech.sumitbt.repositories.UserRepo;

@RestController
public class BookControllers
{
	@Autowired
	private BookRepo bookRepo;
	
	@Autowired
	private UserRepo userRepo;
	
	@ResponseBody
	@RequestMapping(value="/book",method=RequestMethod.GET)
	public Iterable<Book> getAll()
	{
	    return bookRepo.findAll();
	}
	
	@RequestMapping(value="/book",method=RequestMethod.POST)
	public String create(@RequestBody Book book)
	{
		if(book==null)
			return "Request body can not be null";
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByUsername(auth.getName());
		if(!user.isEnabled())
		{
			return "Confirm your Email first";
		}
		if(user.getRole().getRolename().equals("Admin"))
		{
			String bookname,authorname;
			bookname=book.getBookname();
			authorname=book.getAuthorname();
			if(bookname.equals(null))
				return "bookname can not be null";
			else if(bookRepo.findByBookname(bookname)!=null)
				return "bookname = "+bookname+" already exists";
			else if(authorname.equals(null))
				return "authorname can not be null";
			else
			{
				try
				{
					bookRepo.save(book);
				}catch(Exception e)
				{
					return "Exception occured while saving book\n Details:\n"+e.toString();
				}
				return "Success";
			}
		}
		else
		{
			return "Only Admin can add Book";
		}
		
	}
	
	@RequestMapping(value="/book/{id}", method=RequestMethod.DELETE)
	public String delete(@PathVariable long id)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByUsername(auth.getName());
		if(!user.isEnabled())
		{
			return "Confirm your Email first";
		}
		if(user.getRole().getRolename().equals("Admin"))
		{
			if(bookRepo.findOne(id)==null)
				return "No Book exist with id="+id;
			else
			{
				try
				{
					bookRepo.delete(id);
				}catch(Exception e)
				{
					return "Exception occured while deleting book\n Details:\n"+e.toString();
				}
				return "Success";
			}
		}
		else
		{
			return "Only Admin can add Book";
		}
	}
	
	@RequestMapping(value="/book/{id}", method=RequestMethod.PUT)
	public String update(@PathVariable long id, @RequestBody Book book)
	{
		if(book==null)
			return "Request body can not be null";
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByUsername(auth.getName());
		if(!user.isEnabled())
		{
			return "Confirm your Email first";
		}
		else
		{
			Book book2 = bookRepo.findOne(id);
			if(book2==null)
			{
				return "No Book exist with id="+id;
			}
			else
			{
				String bookname,authorname;
				bookname=book.getBookname();
				authorname=book.getAuthorname();
				if(bookname.equals(null))
					return "bookname can not be null";
				else if(authorname.equals(null))
					return "authorname can not be null";
				else
				{
					book2.setBookname(bookname);
				    book2.setAuthorname(authorname);
				    try
					{
						bookRepo.save(book2);
					}catch(Exception e)
					{
						return "Exception occured while updating book\n Details:\n"+e.toString();
					}
					return "Success";
				}
			}
		}
	}
}
